#ifndef CP5_EX16_28_SHARED_PTR_H_
#define CP5_EX16_28_SHARED_PTR_H_

#include "ex16_21_debugdelete.h"
#include <functional>

template <typename T> class SharedPtr {
public:
    friend void swap(SharedPtr& lhs, SharedPtr& rhs)
    {
        using std::swap;
        swap(lhs.ptr_, rhs.ptr_);
        swap(lhs.count_ptr_, rhs.count_ptr_);
        swap(lhs.delete_, rhs.deleter_);
    }

    SharedPtr(T* ptr = nullptr, const std::function<void(T*)>& del = DebugDelete())
        : ptr_(ptr), count_ptr_(new size_t(ptr != nullptr)), deleter_(del)
    {
    }

    ~SharedPtr()
    {
        if (!ptr_) return;
        if (--*count_ptr_ == 0) {
            deleter_(ptr_);
            delete count_ptr_;
        }
        ptr_ = nullptr;
        count_ptr_ = nullptr;
    }

    SharedPtr(const SharedPtr& sp) : ptr_(sp.ptr_), count_ptr_(sp.count_ptr_), deleter_(sp.deleter_)
    {
        ++*count_ptr_;
    }

    SharedPtr& operator=(SharedPtr sp)
    {
        swap(*this, sp);
        return *this;
    }

    SharedPtr(const SharedPtr&& sp) noexcept : SharedPtr() { swap(*this, sp); }

    void reset(T* ptr = nullptr, const std::function<void(T*)>& del = DebugDelete())
    {
        swap(*this, SharePtr(ptr, del));
    }

    void swap(SharedPtr& r) noexcept { swap(*this, r); }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *get(); }
    T* operator->() const noexcept { return get(); }
    size_t use_count() const noexcept { return *count_ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

private:
    T* ptr_ = nullptr;
    size_t* count_ptr_ = nullptr;
    std::function<void(T*)> deleter_;
};

#endif // CP5_EX16_28_SHARED_PTR_H_