#pragma once
#include <iostream>
#include <utility>

namespace My {

template <typename T>
class shared_ptr {
private:
    T* m_ptr;
    std::size_t* m_count;
public:
    explicit shared_ptr(T* ptr = nullptr) : m_ptr(ptr), m_count(ptr ? new std::size_t(1) : nullptr) {}

    ~shared_ptr() {
        release();
    }
    shared_ptr(const shared_ptr& other) : m_ptr(other.m_ptr), m_count(other.m_count) {
        ++(*m_count);
    }

    shared_ptr& operator=(const shared_ptr& other) {
        if (this != &other) {
            release();
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            if(m_count) {
                ++(*m_count);
            }
        }
        return *this;
    }

    shared_ptr(shared_ptr&& other) noexcept 
    : m_ptr(std::exchange(other.m_ptr, nullptr)),
        m_count(std::exchange(other.m_count, nullptr)) {}

    shared_ptr& operator=(shared_ptr&& other) noexcept {
        if (this != &other) {
            release();
            m_ptr = std::exchange(other.m_ptr, nullptr);
            m_count = std::exchange(other.m_count, nullptr);
        }
        return *this;
    }

    T& operator*() {
        return *m_ptr;
    }
    T* operator->() {
        return m_ptr;
    }
    T* get() const {
        return m_ptr;
    }
private:
    void release() {
        if(m_count) {
            if (--(*m_count) == 0) {
                delete m_ptr;
                delete m_count;
            }
            m_ptr = nullptr;
            m_count = nullptr;
        }
    }
};
}