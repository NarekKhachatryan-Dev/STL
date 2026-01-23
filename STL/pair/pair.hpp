#pragma once

template <typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair(const T1& a, const T2& b) : first(a), second(b) {}
    pair(T1&& a, T2&& b) : first(std::move(a)), second(std::move(b)) {}
    pair() : first(), second() {}
    pair(const pair& other) : first(other.first), second(other.second) {}
    pair(pair&& other) noexcept : first(std::move(other.first)), second(std::move(other.second)) {}

    pair& operator=(const pair& other) {
        if(this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    pair& operator=(pair&& other) noexcept {
        if(this != &other) {
            first = std::move(other.first);
            second = std::move(other.second);
        }
        return *this;
    }

    pair operator+(const pair& other) const {
        return pair(first + other.first, second+ other.second);
    }

    bool operator==(const pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const pair& other) const {
        return !(*this == other);
    }
};