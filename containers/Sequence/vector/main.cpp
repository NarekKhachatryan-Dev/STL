#include <iostream>
#include <stdexcept>
#include "vector.hpp"

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    try {
        std::cout << "Element at index 10: " << vec.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << std::endl;
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}