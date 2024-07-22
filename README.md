# Demo C++ Concurrency

This repository contains examples of common issues and solutions in C++ concurrency.

## Table of Contents

- [Files](#files)
  - [deadlock.cpp](#deadlockcpp)
  - [deadlock_mutex.cpp](#deadlock_mutexcpp)
  - [race_condition.cpp](#race_conditioncpp)
  - [race_condition_mutex.cpp](#race_condition_mutexcpp)
- [Compiling and Running](#compiling-and-running)
- [Debugging with GDB](#debugging-with-gdb)
- [License](#license)

## Files

### deadlock.cpp
An example of a deadlock where two threads try to lock two mutexes in different orders, leading to mutual blocking.

### deadlock_mutex.cpp
A corrected version of `deadlock.cpp` that avoids the deadlock by ensuring both threads lock the mutexes in the same order.

### race_condition.cpp
An example of a race condition where multiple threads concurrently access and increment a shared variable, leading to inconsistent results.

### race_condition_mutex.cpp
A corrected version of `race_condition.cpp` that avoids the race condition by using a mutex to synchronize access to the shared variable.

## Compiling and Running

To compile the examples, you need a C++ compiler like `g++`:

```sh
g++ -g -o deadlock deadlock.cpp -pthread
g++ -g -o deadlock_mutex deadlock_mutex.cpp -pthread
g++ -g -o race_condition race_condition.cpp -pthread
g++ -g -o race_condition_mutex race_condition_mutex.cpp -pthread
```
To run the programs, use the generated binaries:

```sh
./deadlock
./deadlock_mutex
./race_condition
./race_condition_mutex
```

Debugging with GDB

Use gdb to debug the programs and redirect the output to a file:

```sh
gdb ./deadlock > gdb_output.txt
```
You can also enable logging within gdb:

```sh
gdb ./deadlock
(gdb) set logging file gdb_output.txt
(gdb) set logging enabled on
(gdb) run
(gdb) info threads
(gdb) set logging enabled off
```
## License
This project is licensed under the MIT License. See the LICENSE file for more details.