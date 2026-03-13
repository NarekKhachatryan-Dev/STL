#include "list.hpp"
#include <iostream>
#include <utility>

int main() {
    My::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::cout << "List contents: ";
    lst.print(); // Expected output: 10 20 30

    std::cout << "Is list empty? " << (lst.empty() ? "Yes" : "No") << std::endl;

    My::list<int> lst2 = lst; // Copy constructor
    std::cout << "Copied list contents: ";
    lst2.print(); // Expected output: 10 20 30

    My::list<int> lst3 = std::move(lst); // Move constructor
    std::cout << "Moved list contents: ";
    lst3.print(); // Expected output: 10 20 30
    std::cout << "Original list after move, is empty? " << (lst.empty() ? "Yes" : "No") << std::endl;

    return 0;
}