#include <iostream>
#include "vector.hpp"

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;
    return 0;
}