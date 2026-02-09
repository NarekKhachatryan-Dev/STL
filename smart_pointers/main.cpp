#include <iostream>
#include "unique_ptr.hpp"

int main() {
    My::unique_ptr<int> p(new int(42));
    std::cout << "Value: " << *p << std::endl;

    My::unique_ptr<int> q = std::move(p);
    if (!p.get()) {
        std::cout << "p is now null after move." << std::endl;
    }
    std::cout << "Value from q: " << *q << std::endl;

    int* raw = q.release();
    std::cout << "Released raw pointer value: " << *raw << std::endl;
    delete raw;

    if(q) {
        std::cout << "q is not null." << std::endl;
    } else {
        std::cout << "q is now null after release." << std::endl;
    }

    return 0;
}