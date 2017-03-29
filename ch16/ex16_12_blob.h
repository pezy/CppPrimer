/*
================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

own version of the `Blob`.

If you have questions, try to connect with me: pezy<pezy.dev@gmail.com>
================================================================================
*/

#ifndef CP5_EX16_12_BLOB_H_
#define CP5_EX16_12_BLOB_H_

#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <algorithm>
#include <stdexcept>

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;

//==============================================================================
//
//  Blob - custom vector.
//
//==============================================================================

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class ConstBlobPtr<T>;
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
    // clang-format off
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator> <T>(const Blob<T>&, const Blob<T>&);
    // clang-format on
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);

public:
    typedef typename vector<T>::size_type size_type;

    Blob() : data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

    Blob(const Blob<T>& lhs) : data(make_shared<vector<T>>(*lhs.data)) {}
    Blob& operator=(const Blob<T>&);

    Blob(Blob<T>&& rhs) NOEXCEPT : data(std::move(rhs.data)) {}
    Blob& operator=(Blob<T>&&) NOEXCEPT;

    BlobPtr<T> begin();
    BlobPtr<T> end();

    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

    T& operator[](size_t n);
    const T& operator[](size_t n) const;

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& s) { data->push_back(std::move(s)); }

    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

private:
    void check(size_type, const T&) const;

    shared_ptr<vector<T>> data;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T> bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

template <typename T> bool operator>(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return rhs < lhs;
}

template <typename T> bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(rhs < lhs);
}

template <typename T> bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(lhs < rhs);
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> Blob<T>& Blob<T>::operator=(const Blob<T>& lhs)
{
    data = make_shared<vector<T>>(*lhs.data);
    return *this;
}

template <typename T> Blob<T>& Blob<T>::operator=(Blob<T>&& rhs) NOEXCEPT
{
    if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }

    return *this;
}

template <typename T> BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template <typename T> ConstBlobPtr<T> Blob<T>::cbegin() const
{
    return ConstBlobPtr<T>(*this);
}

template <typename T> ConstBlobPtr<T> Blob<T>::cend() const
{
    return ConstBlobPtr<T>(*this, data->size());
}

template <typename T> inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob<T>");
    data->pop_back();
}

template <typename T> inline T& Blob<T>::front()
{
    check(0, "front on empty Blob<T>");
    return data->front();
}

template <typename T> inline T& Blob<T>::back()
{
    check(0, "back on empty Blob<T>");
    return data->back();
}

template <typename T> inline const T& Blob<T>::front() const
{
    check(0, "front on empty Blob<T>");
    return data->front();
}

template <typename T> inline const T& Blob<T>::back() const
{
    check(0, "back on empty Blob<T>");
    return data->back();
}

template <typename T>
inline void Blob<T>::check(size_type i, const T& msg) const
{
    if (i >= data->size()) throw std::out_of_range(msg);
}

template <typename T> inline T& Blob<T>::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

template <typename T> inline const T& Blob<T>::operator[](size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

//=================================================================================
//
//		BlobPtr - custom iterator of Blob
//
//=================================================================================

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    // clang-format off
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    // clang-format on
    friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    T& deref() const;
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr& operator+=(size_t);
    BlobPtr& operator-=(size_t);
    BlobPtr operator+(size_t) const;
    BlobPtr operator-(size_t) const;

    T& operator[](size_t n);
    const T& operator[](size_t n) const;

private:
    shared_ptr<vector<T>> check(size_t, const T&) const;

    std::weak_ptr<vector<T>> wptr;
    size_t curr;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T> bool operator<(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr < y.curr;
}

template <typename T> bool operator>(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr > y.curr;
}

template <typename T> bool operator<=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr <= y.curr;
}

template <typename T> bool operator>=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr >= y.curr;
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> inline T& BlobPtr<T>::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of Blob<T>Ptr");
    ++curr;
    return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of Blob<T>Ptr");
    return *this;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const T& msg) const
{
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

template <typename T> inline T& BlobPtr<T>::operator[](size_t n)
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

template <typename T> inline const T& BlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

//=================================================================================
//
//		ConstBlobPtr - custom const_iterator of Blob
//
//=================================================================================

template <typename T>
bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

template <typename T> class ConstBlobPtr {
    friend bool operator==<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator!=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format off
    friend bool operator< <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator> <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format on
    friend bool operator<=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator>=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

public:
    ConstBlobPtr() : curr(0) {}
    ConstBlobPtr(const Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    const T& operator*() const;
    const T* operator->() const;
    ConstBlobPtr& operator++();
    ConstBlobPtr& operator--();
    ConstBlobPtr operator++(int);
    ConstBlobPtr operator--(int);
    ConstBlobPtr& operator+=(size_t);
    ConstBlobPtr& operator-=(size_t);
    ConstBlobPtr operator+(size_t) const;
    ConstBlobPtr operator-(size_t) const;

    const T& operator[](size_t n) const;

private:
    std::shared_ptr<vector<T>> check(size_t, const T&) const;

    std::weak_ptr<vector<T>> wptr;
    size_t curr;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T>
bool operator==(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr > rhs.curr;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr <= rhs.curr;
}

template <typename T>
bool operator>=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr >= rhs.curr;
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> inline const T& ConstBlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T> inline const T* ConstBlobPtr<T>::operator->() const
{
    return &this->operator*();
}

template <typename T> inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator++()
{
    check(curr, "increment past end of ConstBlob<T>Ptr");
    ++curr;
    return *this;
}

template <typename T> inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of ConstBlob<T>Ptr");
    return *this;
}

template <typename T> inline ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
    ConstBlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T> inline ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
    ConstBlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator+(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator-(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline std::shared_ptr<vector<T>> ConstBlobPtr<T>::check(size_t i,
                                                         const T& msg) const
{
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

template <typename T>
inline const T& ConstBlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

#endif // CP5_EX16_12_BLOB_H_
