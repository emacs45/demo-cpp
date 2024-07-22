#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mutex1;
mutex mutex2;

void process1() {
    // Sperren beider Mutexes in der gleichen Reihenfolge
    lock(mutex1, mutex2);
    lock_guard<mutex> lock1(mutex1, adopt_lock);
    lock_guard<mutex> lock2(mutex2, adopt_lock);
    // Simulate some work
    this_thread::sleep_for(chrono::milliseconds(100)); 
    cout << "Process 1 acquired both mutexes." << endl;
}

void process2() {
    // Sperren beider Mutexes in der gleichen Reihenfolge
    lock(mutex1, mutex2);
    lock_guard<mutex> lock1(mutex1, adopt_lock);
    lock_guard<mutex> lock2(mutex2, adopt_lock);
    // Simulate some work
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Process 2 acquired both mutexes." << endl;
}

int main() {
    thread t1(process1);
    thread t2(process2);

    t1.join();
    t2.join();

    return 0;
}