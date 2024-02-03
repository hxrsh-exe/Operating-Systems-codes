#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

int main() {
    int n;
    cout << "Enter no. of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time, burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1;
    }
    sort(processes.begin(), processes.end(), compareArrivalTime);
    int completion = 0;
    float totalwt = 0.0, totaltat = 0.0;

    for (int i = 0; i < n; ++i) {
        if (completion < processes[i].arrivalTime) {
            completion = processes[i].arrivalTime;
        }

        completion += processes[i].burstTime;

        int tat = completion - processes[i].arrivalTime;
        int wt = tat - processes[i].burstTime;

        totaltat += tat;
        totalwt += wt;

        cout << "Process " << processes[i].id
             << " - Turnaround Time: " << tat
             << ", Waiting Time: " << wt << endl;
    }
    float avgtat = totaltat / n;
    float avgwt = totalwt / n;

    cout << "Average Turnaround Time: " << avgtat << endl;
    cout << "Average Waiting Time: " << avgwt << endl;

    return 0;
}
