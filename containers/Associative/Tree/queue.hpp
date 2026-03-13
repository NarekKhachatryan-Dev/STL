#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"
#include <cstddef>
#include <utility>

template <typename T>
class Queue {
public:
    void enqueue(const T& value) {
        storage_.push_back(value);
        ++size_;
    }

    void enqueue(T&& value) {
        storage_.push_back(std::move(value));
        ++size_;
    }

    T dequeue() {
        T value = std::move(storage_.front());
        storage_.pop_front();
        --size_;
        return value;
    }

    bool empty() const {
        return storage_.empty();
    }

    std::size_t size() const {
        return size_;
    }

private:
    mylist::list<T> storage_;
    std::size_t size_ = 0;
};

#endif