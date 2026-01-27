#include "list.hpp"
#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue : public List<T> {
    void enqueue(const T& value) {
        this->push_back(value);
    }
    void enqueue(T&& value) {
        this->push_back(std::move(value));
    }
    void dequeue() {
        this->pop_front();
    }

    T& front() {
        return this->head->data;
    }
    const T& front() const {
        return this->head->data;
    }

    bool empty() const {
        return this ->head == nullptr;
    }
    std::size_t size() const {
        return this ->size();
    }
};

#endif