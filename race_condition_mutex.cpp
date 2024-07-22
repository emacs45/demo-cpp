#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

int counter = 0;
mutex counter_mutex;

void increment(int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        // Acquire the mutex
        lock_guard<mutex> lock(counter_mutex);
        // Critical section
        ++counter; 
    } // Release the mutex automatically when lock goes out of scope
}

int main() {
    const int num_threads = 10;
    const int num_iterations = 1000;

    vector<thread> threads;

    // Start multiple threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(thread(increment, num_iterations));
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    // Output the value of counter
    cout << "Final counter value: " << counter << endl;

    return 0;
}

