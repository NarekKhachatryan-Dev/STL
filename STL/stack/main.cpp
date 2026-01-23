#include <iostream>
#include "stack.hpp"

int main() {
    stack<int> s = {1, 2, 3};
    s.push(4);
    s.print();
    std::cout << "Top element: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top element after pop: " << s.top() << std::endl;
    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;
    s.print();
    return 0;
}