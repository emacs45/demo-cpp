#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

int counter = 0;

void increment(int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        // Simulate work to increase the chance of a race condition
        this_thread::sleep_for(chrono::microseconds(1));
        // Race condition occurs here
        ++counter; 
    }
}

int main() {
    const int num_threads = 10;
    const int num_iterations = 10000;

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


