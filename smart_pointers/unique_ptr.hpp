#pragma once
#include <iostream>
#include <memory>

namespace My {
template <typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
    private:
        T* ptr;
        Deleter deleter;

    public:
        explicit unique_ptr(T* p = nullptr, Deleter d = Deleter()) : ptr(p), deleter(d) {}
        ~unique_ptr() {
            deleter(ptr);
        }
        
        unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr), deleter(std::move(other.deleter)) {
            other.ptr = nullptr;
        }

        operator bool() const {
            return ptr != nullptr;
        }

        unique_ptr& operator=(unique_ptr&& other) noexcept {
            if(this != &other) {
                deleter(ptr);
                ptr = other.ptr;
                deleter = std::move(other.deleter);
                other.ptr = nullptr;
            }
            return *this;
        }

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        T* get() const {
            return ptr;
        }

        void reset(T* p = nullptr) {
            deleter(ptr);
            ptr = p;
        }

        T* release() {
            T* temp = ptr;
            ptr = nullptr;
            return temp;
        }
};
}