// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <atomic>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

namespace moderncpp::chap07 {
using std::cout, std::thread;

class ThreadPool {
private:
    int max{0};
public:
    explicit ThreadPool(int32_t v);

    // destroy thread pool and all created threads
    ~ThreadPool() = default;
};

ThreadPool::ThreadPool(int32_t v) : max(v) {}

static int value = 0, value3 = 100;

void main2() {
    static std::mutex mtx{};
    std::lock_guard<std::mutex> lock{mtx};  // if without this line , maybe output is 0,1,0,2
    std::cout << value << std::endl;
    value += 1;
    std::cout << value << std::endl;
}

void main3() {
    static std::mutex mtx{};
    std::unique_lock<std::mutex> lock{mtx};  // if without this line , maybe output is 0,1,0,2
    std::cout << value3 << std::endl;
    value3 += 1;
    std::cout << value3 << std::endl;
    lock.unlock();
    std::cout << value3 << std::endl;
    value3 += 1;
    std::cout << value3 << std::endl;
}


int main() {
    std::thread t{[]() {
        std::cout << "hello world." << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    }};
    t.join();
    std::thread t2{main2}, t3{main2};
    t3.join();
    t2.join();
    std::thread t4{main3}, t5{main3};
    t5.join();
    t4.join();
    return 0;
}
}

int main() {
    return moderncpp::chap07::main();
}
