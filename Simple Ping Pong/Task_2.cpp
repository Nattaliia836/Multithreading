#include <iostream>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <thread>

std::condition_variable condition;
std::mutex mtx;
std::atomic<bool> flag_thread = true;  

void thread0(int count)
{
    std::unique_lock<std::mutex> lk(mtx);
    for (int i = 0; i < count; i++)
    {
        condition.wait(lk, [] {return flag_thread ? true : false;});
        std::cout << "ping\n";
        flag_thread = !flag_thread;
        condition.notify_one();
    }
}

void thread1(int count)
{
    std::unique_lock<std::mutex> lk(mtx);
    for (int i = 0; i < count; i++)
    {
        condition.wait(lk, [] {return !flag_thread; });
        std::cout << "pong\n";
        flag_thread = !flag_thread;
        condition.notify_one();
    }
}

int main()
{
    int count = 10000;
    std::thread t1(thread0, count);
    std::thread t2(thread1, count);
    t1.join();
    t2.join();
    return 0;
}