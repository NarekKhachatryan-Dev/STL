#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <queue>

std::condition_variable cv_consumer;
std::condition_variable cv_producer;
std::mutex mtx;

const int max_size = 10;

void consumer(std::queue<int>& data_queue) {
    for(int i = 0; i < max_size; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [&data_queue] { return data_queue.size() > 0; });
        int value = data_queue.front();
        data_queue.pop();
        std::cout << "Consumer: Got value " << value << std::endl;
        cv_producer.notify_one();
    }
}

void producer(std::queue<int>& data_queue) {
    for(int i = 0; i < max_size; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_producer.wait(lock, [&data_queue] { return data_queue.size() < 5; });
        data_queue.push(i);
        std::cout << "Producer: Produced value " << i << std::endl;
        cv_consumer.notify_one();
    }
}

int main() {
    std::queue<int> data_queue;

    std::thread prod_thread(producer, std::ref(data_queue));
    std::thread cons_thread(consumer, std::ref(data_queue));

    prod_thread.join();
    cons_thread.join();

    return 0;
}