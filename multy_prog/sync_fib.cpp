#include <iostream>
#include <future>
#include <atomic>

const int MAX_FIB = 92;
std::atomic<long long> fib_cache[MAX_FIB + 1];

long long fib(int n) {
    if (n <= 1) return n;
    
    if (fib_cache[n] != 0) return fib_cache[n];
    
    long long a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    
    fib_cache[n] = result;
    return result;
}

int main() {
    long long nums[] = {30, 35, 40};
    
    for (int i = 0; i < 3; i++) {
        std::future<long long> result = std::async(std::launch::async, fib, nums[i]);
        std::cout << "Fibonacci of " << nums[i] << " is: " << result.get() << std::endl;
    }
    return 0;
}