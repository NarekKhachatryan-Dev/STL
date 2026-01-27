#pragma once
#include <iostream>
#include <initializer_list>
#include "../vector/vector.hpp"

template <typename T>
class stack : private vector<T> {
    public:
    stack() : vector<T>() {}
    stack(std::initializer_list<T> init) : vector<T>(init) {}

    void push(const T& value) {
        this -> push_back(value);
    }
    void pop() {
        this -> pop_back();
    }

    T& top() {
        return this -> operator[](this -> size() - 1);
    }

    bool empty() const {
        return this -> vector<T>::empty();
    }

    void print() const {
        for (size_t i = 0; i < this -> size(); ++i) {
            std::cout << this -> operator[](i) << " ";
        }
        std::cout << std::endl;
    }
};