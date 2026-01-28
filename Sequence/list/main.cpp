#include "list.hpp"
#include <iostream>

int main() {
    mylist::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(41);

    std::cout << "List contents: ";
    lst.print();

    std::cout << "Is list empty? " << (lst.empty() ? "Yes" : "No") << std::endl;

    mylist::list<int> lst2 = lst;
    std::cout << "Copied list contents: ";
    lst2.print();

    mylist::list<int> lst3 = std::move(lst);
    std::cout << "Moved list contents: ";
    lst3.print();
    std::cout << "Original list after move, is empty? " << (lst.empty() ? "Yes" : "No") << std::endl;

    delete_odd(lst3);
    std::cout << "List after deleting odd elements: ";
    lst3.print();

    return 0;
}