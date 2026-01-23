#pragma once
#include <initializer_list>
#include "../vector/vector.hpp"

template <typename T>
class queue : private vector<T> {
    public:
    queue() : vector<T>() {}
    queue(std::initializer_list<T> init) : vector<T>(init) {}

    void push(const T& value) {
        this->push_back(value);
    }

    void pop() {
        if (this->empty()) {
            return;
        }
        for (size_t i = 1; i < this->size(); ++i) {
            (*this)[i - 1] = (*this)[i];
        }
        this->pop_back();
    }

    T& front() {
        return vector<T>::front();
    }

    size_t size() const {
        return vector<T>::size();
    }

    bool empty() const {
        return vector<T>::empty();
    }

    bool operator==(const queue& other) const {
        return vector<T>::operator==(other);
    }

    void clear() {
        vector<T>::clear();
    }
};