#ifndef CP5_EX16_28_SHARED_PTR_H_
#define CP5_EX16_28_SHARED_PTR_H_

template <typename T> class SharedPtr {
    using DelFuncPtr = void (*)(T*);

public:
    SharedPtr(T* ptr = nullptr, DelFuncPtr del = nullptr)
        : ptr_(ptr), count_ptr_(new size_t(ptr != nullptr)), del_(del)
    {
    }

    ~SharedPtr()
    {
        if (!ptr_) return;
        if (--*count_ptr_ == 0) {
            del_ ? del_(ptr_) : delete ptr_;
            delete count_ptr_;
        }
        ptr_ = nullptr;
        count_ptr_ = nullptr;
    }

    SharedPtr(const SharedPtr& sp) : ptr_(sp.ptr_), count_ptr_(sp.count_ptr_), del_(sp.del_)
    {
        ++*count_ptr_;
    }

    SharedPtr& operator=(SharedPtr sp)
    {
        swap(sp);
        return *this;
    }

    SharedPtr(const SharedPtr&& sp) noexcept : SharedPtr() { swap(sp); }

    void reset(T* ptr = nullptr, DelFuncPtr del = nullptr)
    {
        SharedPtr tmp(ptr, del);
        swap(tmp);
    }

    void swap(SharedPtr& r) noexcept
    {
        using std::swap;
        swap(ptr_, r.ptr_);
        swap(count_ptr_, r.count_ptr_);
        swap(del_, r.del_);
    }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *get(); }
    T* operator->() const noexcept { return get(); }
    size_t use_count() const noexcept { return *count_ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

private:
    T* ptr_ = nullptr;
    size_t* count_ptr_ = nullptr;
    DelFuncPtr del_ = nullptr;
};

#endif // CP5_EX16_28_SHARED_PTR_H_