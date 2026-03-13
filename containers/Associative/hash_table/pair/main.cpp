#include <iostream>
#include "pair.hpp"

int main() {
    My::pair<int, double> p1(3, 4.5);
    My::pair<int, double> p2(2, 3.5);

    My::pair<int, double> p3 = p1 + p2;

    std::cout << "p3.first: " << p3.first << ", p3.second: " << p3.second << std::endl;

    if (p1 != p2) {
        std::cout << "p1 and p2 are not equal." << std::endl;
    }

    My::pair<std::string, std::string> p4("Hello, ", "Goodbye, ");
    My::pair<std::string, std::string> p5("World! ", "Everyone!");

    My::pair<std::string, std::string> p6 = p4 + p5;

    std::cout << "p6.first: " << p6.first << ", p6.second: " << p6.second << std::endl;

    return 0;
}