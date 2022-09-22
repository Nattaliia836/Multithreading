#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>
#include <cstdlib>

using namespace std;

atomic<int> number = 1;
mutex mtx;


void thread1() {

    this_thread::sleep_for(chrono::seconds((rand() % 10)));

    while (true) {
        if (number == 1) {
            mtx.lock();
            cout << "1" << endl;
            number++;
            mtx.unlock();
            break;
        }
    }

}

void thread2() {

    this_thread::sleep_for(chrono::seconds((rand() % 10)));
    
    while (true) {
        if (number == 2) {
            mtx.lock();
            cout << "2" << endl;
            number++;
            mtx.unlock();
            break;
        }
    }
   
}

void thread3() {
    this_thread::sleep_for(chrono::seconds((rand() % 10 + 5)));
    while (true) {
        if (number == 3) {
            mtx.lock();
            cout << "3" << endl;
            number++;
            mtx.unlock();
            break;
        }
    }
}

void thread4() {
    this_thread::sleep_for(chrono::seconds((rand() % 10)));
    while (true) {
        if (number == 4) {
            mtx.lock();
            cout << "4" << endl;
            number++;
            mtx.unlock();
            break;
        }
    }
}

void thread5() {
    this_thread::sleep_for(chrono::seconds((rand() % 10)));
    while (true) {
        if (number == 5) {
            mtx.lock();
            cout << "5" << endl;
            number++;
            mtx.unlock();
            break;
        }
    }
}


int main()
{
    cout << "Main started" << endl;
    
    thread t1(thread1);
    thread t2(thread2);
    thread t3(thread3);
    thread t4(thread4);
    thread t5(thread5);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

}
