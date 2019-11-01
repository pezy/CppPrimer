#ifndef VC_H
#define VC_H

#include <memory>
#include <algorithm>
#include <iostream>
#include <string>

using std::allocator;
using std::uninitialized_copy;
using std::ostream;
using std::cout;
using std::cerr;
using std::endl;
using std::for_each;
using std::swap;
using std::string;
using std::pair;
using std::initializer_list;

// declaration for below templates .
template <typename T> class Vec;

// declaration of each template.
template <typename T> bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator!=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator< (const Vec<T> &, const Vec<T> &);
template <typename T> bool operator> (const Vec<T> &, const Vec<T> &);
template <typename T> bool operator<=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator>=(const Vec<T> &, const Vec<T> &);


template <typename T>
class Vec
{
	// bound template friend.
       	friend bool operator==<T>(const Vec<T> &, const Vec<T> &);
       	friend bool operator!=<T>(const Vec<T> &, const Vec<T> &);
       	friend bool operator< <T>(const Vec<T> &, const Vec<T> &);
       	friend bool operator> <T>(const Vec<T> &, const Vec<T> &);
       	friend bool operator<=<T>(const Vec<T> &, const Vec<T> &);
       	friend bool operator>=<T>(const Vec<T> &, const Vec<T> &);

    public:
        Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        Vec(initializer_list<T>);
        Vec(const Vec &);
        Vec(Vec &&) noexcept;
        Vec & operator=(const Vec &);
        Vec & operator=(Vec &&) noexcept;
        ~Vec() noexcept;
       
        T * begin() const;
        T * end() const;
        size_t size() const;
        size_t capacity() const;
        T & operator[](size_t);
        const T & operator[](size_t) const;
        void push_back(const T &);
        void push_back(T &&);                         // used for rvalue
        void reserve(size_t);
        void resize(size_t, const T & val = T());
        void free();

        template <typename ... Args>
        void emplace_back(Args && ...);
        void swap(Vec &) noexcept;
    private:
        static allocator<T> alloc;
        T * elements;
        T * first_free;
        T * cap;
        pair<T *, T *> alloc_n_copy(const T * const &, const T * const &);
        void chk_n_alloc();
        void reallocate(size_t max=0);
};

template <typename T>
allocator<T> Vec<T>::alloc;

template <typename T>
inline Vec<T>::Vec(initializer_list<T> init_l) : Vec()
{
    pair<T *, T *> p = alloc_n_copy(init_l.begin(), init_l.end());
    elements = p.first;
    first_free = cap = p.second;
}

template <typename T>
inline Vec<T>::Vec(const Vec & v)
{
    pair<T *, T *> p = alloc_n_copy(v.begin(), v.end());
    elements = p.first;
    first_free = cap = p.second;
}

template <typename T>
inline Vec<T>::Vec(Vec && v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap)
{
    v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
inline Vec<T> & Vec<T>::operator=(const Vec & v)
{
    if (this != &v)
    {
        free();
        pair<T *, T *> p = alloc_n_copy(v.begin(), v.end());
        elements = p.first;
        first_free = cap = p.second;
    }
    return *this;
}

template <typename T>
inline Vec<T> & Vec<T>::operator=(Vec && v) noexcept
{
    if (this != &v)
    {
        free();
        swap(v);
    }
    return *this;
}

template <typename T>
inline Vec<T>::~Vec() noexcept
{
    if (elements && first_free && cap)
        free();
}

template <typename T>
inline T * Vec<T>::begin() const
{
    return elements;
}

template <typename T>
inline T * Vec<T>::end() const
{
    return first_free;
}

template <typename T>
inline size_t Vec<T>::size() const
{
    return first_free - elements;
}

template <typename T>
inline size_t Vec<T>::capacity() const
{
    return cap - elements;
}

template <typename T>
inline T & Vec<T>::operator[](size_t index)
{
    if (index > 0 && index < size())
        return *(elements + index);
    else
        cerr << "Index error:\nmax_index: " << size() - 1
             << " input index: " << index << endl;
    exit(EXIT_FAILURE);
}
template <typename T>
inline const T & Vec<T>::operator[](size_t index) const
{
    if (index > 0 && index < size())
        return *(elements + index);
    else
        cerr << "Index error:\nmax_index: " << size() - 1
             << " input index: " << index << endl;
    exit(EXIT_FAILURE);
}

template <typename T>
inline void Vec<T>::push_back(const T & t)
{
   chk_n_alloc();
   alloc.construct(first_free++, t);
}

template <typename T>
inline void Vec<T>::push_back(T && t)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(t));
}

template <typename T>
inline void Vec<T>::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

template <typename T>
void Vec<T>::resize(size_t n, const T & val)
{
    if (n < size())
    {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
    else
    {
        if (n > capacity())
            reserve(n);
        while (first_free != elements + n)
            alloc.construct(first_free++, val);
    }
}

template <typename T>
void Vec<T>::free()
{
    for_each(first_free, first_free, [](T & t) {alloc.destroy(&t);});
    alloc.deallocate(elements, cap - elements);
    elements = first_free = cap = nullptr;
}

template <typename T>
template <typename ... Args>
inline void Vec<T>::emplace_back(Args && ... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
inline void Vec<T>::swap(Vec & v) noexcept
{
    std::swap(elements, v.elements);
    std::swap(first_free, v.first_free);
    std::swap(cap, v.cap);
}

template <typename T>
inline pair<T *, T *> Vec<T>::alloc_n_copy(const T * const & st, const T * const & end)
{
    T * start = alloc.allocate(end - st);
    return {start, uninitialized_copy(st, end, start)};
}

template <typename T>
inline void Vec<T>::chk_n_alloc()
{
   if (size() == capacity())
       reallocate();
}

template <typename T>
void Vec<T>::reallocate(size_t max)
{
    size_t newcapacity = max ? 2 * max : (size() ? 2 * size() : 1);
    T * newstart = alloc.allocate(newcapacity);
    T * dest = newstart;
    for_each(elements, first_free, [&dest](T & elem) {alloc.construct(dest++, std::move(elem));});
    free();
    elements = newstart;
    first_free = dest;
    cap = newstart + newcapacity;
}

template <typename T>
bool operator==(const Vec<T> & v1, const Vec<T> & v2)
{
   return v1.size() == v2.size() && std::equal(v1.begin(), v1.end(), v2.begin());
}

template <typename T>
inline bool operator!=(const Vec<T> & v1, const Vec<T> & v2)
{
   return !(v1 == v2);
}

template <typename T>
bool operator<(const Vec<T> & v1, const Vec<T> & v2)
{
   return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
}

template <typename T>
bool operator>(const Vec<T> & v1, const Vec<T> & v2)
{
   return v2 < v1;
}

template <typename T>
bool operator<=(const Vec<T> & v1, const Vec<T> & v2)
{
   return !(v2 < v1);
}

template <typename T>
bool operator>=(const Vec<T> & v1, const Vec<T> & v2)
{
   return !(v1 < v2);
}


int main()
{
    // construc and move.
    Vec<int> a = {1, 2, 3, 4, 5, 6, 7};
    for_each(a.begin(), a.end(), [](const int & i) {cout  << i << endl;});
    Vec<int> b(std::move(a));
    b.push_back(8);
    for_each(b.begin(), b.end(), [](const int & i) {cout  << i << endl;});
    Vec<int> c = std::move(b);

    // resize.
    c.resize(10);
    for_each(c.begin(), c.end(), [](const int & i) {cout  << i << endl;});

    // emplace.
    c.emplace_back(4);
    for_each(c.begin(), c.end(), [](const int & i) {cout  << i << endl;});

    Vec<string> vs;
    vs.push_back("first string");
    vs.emplace_back(10, 'c');
    for_each(vs.begin(), vs.end(), [](const string & i) {cout  << i << endl;});
}

#endif


