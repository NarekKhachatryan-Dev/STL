#include <iostream>
#include <future>

long long fib(unsigned n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    long long nums[] = {30, 35, 40};
    
    for (int i = 0; i < 3; i++) {
        std::future<long long> result = std::async(std::launch::async, fib, nums[i]);
        std::cout << "Fibonacci of " << nums[i] << " is: " << result.get() << std::endl;
    }
    return 0;
}