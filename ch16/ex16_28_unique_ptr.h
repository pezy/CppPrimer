#ifndef CP5_EX16_28_UNIQUE_PTR_H_
#define CP5_EX16_28_UNIQUE_PTR_H_

class Delete {
public:
    template <typename T> void operator()(T* ptr) const { delete ptr; }
};

template <typename T, typename D = Delete> class UniquePtr {
public:
    UniquePtr(T* ptr = nullptr, const D& d = D()) noexcept : ptr_(ptr), deleter_(d) {}
    ~UniquePtr() { deleter_(ptr_); }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_), deleter_(std::move(other.deleter_))
    {
        other.ptr_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other) {
            reset();
            ptr_ = other.ptr_;
            deleter_ = std::move(other.deleter_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    UniquePtr& operator=(std::nullptr_t) noexcept
    {
        reset();
        return *this;
    }

    T* release() noexcept
    {
        T* ret = ptr_;
        ptr_ = nullptr;
        return ret;
    }

    void reset(T* q = nullptr) noexcept
    {
        deleter_(q);
        ptr_ = q;
    }

    void swap(UniquePtr& other) noexcept
    {
        using std::swap;
        swap(ptr_, other.ptr_);
        swap(deleter_, other.deleter_);
    }

    T* get() const noexcept { return ptr_; }
    D& get_deleter() noexcept { return deleter_; }
    const D& get_deleter() const noexcept { return deleter_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }
    T& operator*() const { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    T& operator[](size_t i) const { return ptr_[i]; }

private:
    T* ptr_ = nullptr;
    D deleter_;
};

#endif // CP5_EX16_28_UNIQUE_PTR_H_