# Multithreaded Log Analyzer in C++17

## Project Overview

The **Multithreaded Log Analyzer** is a modern system-oriented C++ project developed using **C++17**, **STL**, **multithreading**, and **mutex synchronization** concepts.  

This application reads a log file containing different categories of system-generated messages such as:

- INFO
- WARNING
- ERROR

The program processes these logs using multiple threads simultaneously and generates a summarized analytical report showing categorized log counts.

This project demonstrates practical implementation of:
- Modern C++ concepts
- Parallel processing
- Thread synchronization
- File handling
- Concurrent execution
- STL containers

---

# Why I Built This Project

I developed this project to gain practical exposure to **real-world C++ system programming concepts** instead of building a simple CRUD-based application.

In real-world software systems, applications continuously generate logs for:
- Monitoring software behavior
- Detecting failures
- Tracking application performance
- Debugging system crashes
- Analyzing server activities

Large-scale systems generate huge amounts of log data every day. Processing such large data sequentially becomes inefficient. Therefore, this project uses **multithreading** to process logs concurrently and improve efficiency.

This project also helped me understand:
- Thread creation using `std::thread`
- Thread synchronization using `mutex`
- Race conditions
- Parallel processing
- Thread-safe programming
- Modern C++17 features

The project aligns well with:
- Semiconductor-oriented roles
- System software development
- Linux-based environments
- Performance-oriented applications

---

# Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Core programming language |
| STL | Dynamic containers and string processing |
| Multithreading | Parallel execution |
| Mutex | Thread synchronization |
| fstream | File handling |
| GCC 16.1.0 | Compilation |
| Visual Studio Code | Development environment |

---

# Project Structure

```bash
cpp-multithreaded-log-analyzer/
│
├── main.cpp
├── logs.txt
└── README.md
```

---

# Sample Log File

```txt
INFO: Server started
WARNING: High memory usage
ERROR: Database connection failed
INFO: User login successful
ERROR: Timeout occurred
WARNING: CPU usage high
INFO: Request processed
ERROR: File not found
INFO: Service restarted
WARNING: Disk space low
ERROR: Authentication failed
INFO: Backup completed
```

---
# Sample Output

```txt
===== LOG ANALYSIS REPORT =====

Total Logs    : 12
INFO Logs     : 5
WARNING Logs  : 3
ERROR Logs    : 4

Analysis Completed Successfully!
```

---
# How the Project Works

## Step 1 — Reading Log File 
The application opens the `logs.txt` file using file handling concepts provided by the `fstream` library.

All log entries are read line-by-line and stored dynamically inside a:

```cpp
vector<string>
```

container.

---

## Step 2 — Dividing the Workload
The total log data is divided into multiple parts.

Example:
- Thread 1 → Processes first half of logs
- Thread 2 → Processes second half of logs

This enables concurrent execution.

---

## Step 3 — Multithreaded Processing
The project uses:

```cpp
std::thread
```

to create worker threads.

Each thread independently processes a portion of the log data and counts:
- INFO logs
- WARNING logs
- ERROR logs

---

## Step 4 — Thread Synchronization Using Mutex
Since multiple threads update shared variables simultaneously, race conditions may occur.
To avoid data corruption, the project uses:

```cpp
std::mutex
```

along with:

```cpp
lock_guard<mutex>
```

to ensure thread-safe execution.
Only one thread can update shared counters at a time.

---

## Step 5 — Generating Final Report
After thread execution completes, the application displays a final report containing:
- Total number of logs
- INFO count
- WARNING count
- ERROR count

---

# Main Concepts Implemented

## 1. Multithreading
Multithreading allows multiple tasks to execute simultaneously. 
Instead of processing the entire log file sequentially using one thread, this project processes different parts of the file concurrently using multiple threads.
Benefits:
- Faster execution
- Better CPU utilization
- Improved performance

---

## 2. Mutex Synchronization
A mutex acts like a locking mechanism.
When one thread updates shared variables:
- other threads must wait
- data corruption is prevented

This ensures:
- data consistency
- thread safety
- accurate output

---

## 3. File Handling
The project uses:
- `ifstream`
- `getline()`
to read log data from external files.

---

## 4. STL Containers
The project uses:
- `vector`
- `string`
for efficient dynamic data storage and processing.

---

# Advantages of This Project
- Demonstrates modern C++17 concepts
- Shows practical implementation of multithreading
- Demonstrates mutex synchronization
- Improves understanding of concurrency
- Uses real-world system log processing concepts
- Demonstrates STL and file handling usage
- Suitable for system/software engineering interviews
- Aligns with semiconductor-oriented C++ roles

---

# Challenges Faced During Development
One of the major challenges during development was configuring the compiler properly for modern C++ threading support.
Initially, an older MinGW compiler did not support:
- `thread`
- `mutex`
- modern C++17 features

Later, the compiler was upgraded to:
- GCC 16.1.0 using MSYS2
After configuring Visual Studio Code with the updated compiler, the project compiled and executed successfully.

---

# Future Improvements
Future enhancements that can be added to this project include:
- Real-time log monitoring
- Dynamic thread allocation
- GUI integration
- Exporting reports to files
- Timestamp-based filtering
- Processing very large datasets
- Performance benchmarking

---

# Conclusion
This project helped strengthen my understanding of:
- Modern C++17 programming
- Multithreading
- Mutex synchronization
- Thread-safe execution
- STL containers
- File handling
- Concurrent programming concepts
The project also provided practical exposure to real-world system-oriented application development and performance-oriented programming concepts.

---

# Author
**Narendra Chintapalli**
