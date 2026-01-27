#include <iostream>
#include "queue.hpp"

int main() {
    queue<int> q = {1,2,3};

    q.push(4);
    q.push(5);
    std::cout << "Front element: " << q.front() << std::endl;
    q.pop();
    std::cout << "Front element after pop: " << q.front() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;
    return 0;
}