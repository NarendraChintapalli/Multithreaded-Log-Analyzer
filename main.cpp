#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

// Shared counters
int errorCount = 0;
int warningCount = 0;
int infoCount = 0;

// Mutex for thread safety
mutex mtx;

// Function to process logs
void processLogs(const vector<string>& logs, int start, int end)
{
    int localError = 0;
    int localWarning = 0;
    int localInfo = 0;

    for (int i = start; i < end; i++)
    {
        if (logs[i].find("ERROR") != string::npos)
        {
            localError++;
        }
        else if (logs[i].find("WARNING") != string::npos)
        {
            localWarning++;
        }
        else if (logs[i].find("INFO") != string::npos)
        {
            localInfo++;
        }
    }

    // Lock before updating shared variables
    lock_guard<mutex> lock(mtx);

    errorCount += localError;
    warningCount += localWarning;
    infoCount += localInfo;
}

int main()
{
    vector<string> logs;
    string line;

    // Open log file
    ifstream file("logs.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Read all lines
    while (getline(file, line))
    {
        logs.push_back(line);
    }

    file.close();

    size_t totalLogs = logs.size();

    // Divide logs into 2 parts
    int mid = totalLogs / 2;

    // Create threads
    thread t1(processLogs, ref(logs), 0, mid);
    thread t2(processLogs, ref(logs), mid, totalLogs);

    // Wait for threads
    t1.join();
    t2.join();

    // Display report
    cout << "\n===== LOG ANALYSIS REPORT =====\n";

    cout << "Total Logs    : " << totalLogs << endl;
    cout << "INFO Logs     : " << infoCount << endl;
    cout << "WARNING Logs  : " << warningCount << endl;
    cout << "ERROR Logs    : " << errorCount << endl;

    cout << "\nAnalysis Completed Successfully!" << endl;

    return 0;
}