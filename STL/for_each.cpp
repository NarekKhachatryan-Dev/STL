#include <iostream>
#include <vector>
#include <algorithm>

template<class inputit, class unaryop>
constexpr unaryop my_for_each(inputit first, inputit last, unaryop f) {
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    my_for_each(vec.begin(), vec.end(), [](int& n) {
        n *= 2;
    });

    std::cout << "After my_for_each: ";
    for (const auto& n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::for_each(vec.begin(), vec.end(), [](int& n) {
        n += 1;
    });

    std::cout << "After std::for_each: ";
    for (const auto& n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}