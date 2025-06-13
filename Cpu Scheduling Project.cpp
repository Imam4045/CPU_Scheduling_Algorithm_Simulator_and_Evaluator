/*
    Name: Md.Imam Hasan
*/

#include <bits/stdc++.h>
using namespace std;

// Define process structure to hold details for scheduling
struct Process {
    int pid;                    // Process ID
    int burstTime;              // Burst time of the process
    int waitingTime;            // Waiting time for the process
    int turn_around_time;       // Turnaround time of the process
    int priority;               // Priority of the process (for priority scheduling)
    int remaining;              // Remaining burst time (used in Round Robin)
    int starting_time;          // Start time of the process
    int completion_time;        // Completion time of the process
};

/* Function to take user input for process details
 * @Parameters:
 *  - Process p[]: an array of Process structures to store process details
 *  - int n: the number of processes
 *  - bool isPriority: a flag indicating if priority values should be input
 * Functionality: Reads burst time (and priority, if applicable) for each process, ensuring valid input.
 */
void InputProcesses(Process p[], int n, bool isPriority) {

    for (int i = 0; i < n; i++) {

        p[i].pid = i + 1;
        while (true) {
            cout << "Enter Burst Time for Process P" << p[i].pid << ": ";
            cin >> p[i].burstTime;
            if (cin.fail() || p[i].burstTime<= 0) {
                cout << "Error: Burst time must be a positive integer.\n";
                cin.clear();  
                cin.ignore();  
            } 
            else {
                break;
            }
        }
        p[i].remaining = p[i].burstTime;
        if (isPriority) {
            while (true) {
                cout << "Enter Priority for Process P" << p[i].pid << ": ";
                cin >> p[i].priority;
                if (cin.fail() || p[i].priority <= 0) {
                    cout << "Error: Priority must be a positive integer.\n";
                    cin.clear();  // Clear error flag
                    cin.ignore();  // Discard invalid input
                } 
                else {
                    break;
                }
            }
        }
    }
}

/* Function to calculate the average waiting time
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 * Return Type: double - the average waiting time
 * Functionality: Calculates and returns the average waiting time for all processes.
 */
double CalculateAverageWT(Process p[], int n) {

    double TotalWaiting_Time = 0;
    for (int i = 0; i < n; i++) {

        TotalWaiting_Time += p[i].waitingTime;
    }
    return TotalWaiting_Time / n;
}

/* Function to display scheduling results
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 *  - const char* algorithm: a string representing the scheduling algorithm name
 * Functionality: Displays process details (PID, burst time, waiting time) and average waiting time.
 */
void DisplayResults(Process p[], int n, const char* algorithm) {

    double totalWaitingTime = 0;
    cout << "\n" << algorithm << " Results:\n";
    cout << "----------------------------------\n";
    cout << "PID\t\tBurst Time\t\tWaiting Time\n";
    for (int i = 0; i < n; i++) {

        totalWaitingTime += p[i].waitingTime;
        cout << "P" << p[i].pid << setw(20) << p[i].burstTime << setw(25) << p[i].waitingTime << "\n";
    }
    cout << "Average Waiting Time: " << totalWaitingTime / n << " ms\n";
}

/* Function to display the Gantt chart
 * @Parameters:
 *  - int process_ids[]: an array of process IDs representing execution order
 *  - int times[]: an array of time markers corresponding to process execution
 *  - int size: the number of processes in the Gantt chart
 * Functionality: Displays the Gantt chart with process execution order and time markers.
 */
void DisplayGanttChart(int process_ids[], int times[], int size) {

    cout << "\nGantt Chart:\n";
    cout << "\n|";
    for (int i = 0; i < size; i++) {
        cout << " " << "P" << process_ids[i] << "  |";
    }
    cout << "\n0";
    for (int i = 1; i <= size; i++) {
        cout << setw(6) << times[i];
    }
    cout << "\n";
}

/* Function to simulate First-Come-First-Serve (FCFS) Scheduling
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 * Functionality: Simulates FCFS scheduling, calculates waiting times, and displays results.
 */
void fcfs(Process p[], int n) {

    int time = 0; //initializes a simulation clock that tracks the progression of time during scheduling.

    int process_ids[n], times[n + 1];
    for (int i = 0; i < n; i++) {
        p[i].waitingTime = time;
        time += p[i].burstTime;
        process_ids[i] = p[i].pid;
        times[i] = p[i].waitingTime;
    }
    times[n] = time;
    DisplayResults(p, n, "FCFS");
    DisplayGanttChart(process_ids, times, n);
}

/* Function to simulate Shortest Job First (SJF) Scheduling
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 * Functionality: Sorts processes by burst time, calculates waiting times, and displays results.
 */
void sjf(Process p[], int n) {

    int time = 0;
    int process_ids[n], times[n + 1];
    // Sort processes by burst time (SJF)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (p[i].burstTime > p[j].burstTime) {

                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {

        p[i].waitingTime = time;
        time += p[i].burstTime;
        process_ids[i] = p[i].pid;
        times[i] = p[i].waitingTime;
    }
    times[n] = time;
    DisplayResults(p, n, "SJF");
    DisplayGanttChart(process_ids, times, n);
}

/* Function to simulate Round Robin (RR) Scheduling
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 *  - int tq: the time quantum for Round Robin
 * Functionality: Simulates Round Robin scheduling using the time quantum, calculates waiting times, and displays results.
 */
void roundRobin(Process p[], int n, int tq) {

    int time = 0, completed = 0;
    int process_ids[100], timeMarks[101];
    int timelineSize = 0;

    while (completed < n) {

        for (int i = 0; i < n; i++) {

            if (p[i].remaining > 0) {

                process_ids[timelineSize] = p[i].pid;
                timeMarks[timelineSize] = time;
                timelineSize++;
                int timeSlice = min(tq, p[i].remaining);
                p[i].remaining -= timeSlice;
                time += timeSlice;

                if (p[i].remaining == 0) {

                    p[i].turn_around_time = time;
                    p[i].waitingTime= p[i].turn_around_time - p[i].burstTime;
                    completed++;
                }
            }
        }
    }
    timeMarks[timelineSize] = time;
    DisplayResults(p, n, "Round Robin");
    DisplayGanttChart(process_ids, timeMarks, timelineSize);
}

/* Function to simulate Priority Scheduling
 * @Parameters:
 *  - Process p[]: an array of Process structures
 *  - int n: the number of processes
 * Functionality: Sorts processes by priority, calculates waiting times, and displays results.
 */
void priorityScheduling(Process p[], int n) {

    int time = 0;
    int process_ids[n], times[n + 1];
    // Sort processes by priority
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (p[i].priority > p[j].priority) {

                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {

        p[i].waitingTime = time;
        time += p[i].burstTime;
        process_ids[i] = p[i].pid;
        times[i] = p[i].waitingTime;
    }
    times[n] = time;
    DisplayResults(p, n, "Priority Scheduling");
    DisplayGanttChart(process_ids, times, n);
}

/* Function to evaluate and compare scheduling algorithms
 * Functionality: Evaluates FCFS, SJF, Round Robin, and Priority Scheduling. Calculates average waiting times
 * for each algorithm, displays results, and identifies the best-performing algorithm.
 */
void EvaluateSchedulingAlgorithms() {

    int n, tq;
    cout << "Enter the number of processes: ";
    cin >> n;

    while (n <= 0 || cin.fail()) {
                    
        cin.clear();  // clear error flag
        cin.ignore(); 
                 
        cout << "Error: The number of process must be greater than 0.\nEnter the number of processes: ";
        cin >> n;
    }
    Process p[n], p_fcfs[n], p_sjf[n], p_ps[n], p_rr[n]; // Separate copies for each algorithm

    // Accept process details once
    InputProcesses(p, n, true);

    // Create copies for each algorithm
    for (int i = 0; i < n; i++) {
        p_fcfs[i] = p_sjf[i] = p_ps[i] = p_rr[i] = p[i];
    }
    cout << "Enter Time Quantum for Round Robin: ";
    cin >> tq;
    while (tq <= 0 || cin.fail()) {

        cin.clear();  
        cin.ignore();  // discard invalid input

        cout << "Error: Time Quantum must be greater than 0.\nEnter the Time Quantum: ";
        cin >> tq;
    }

    double FCFS_avgWT, SJF_avgWT, PS_avgWT, RR_avgWT;

    fcfs(p_fcfs, n);
    FCFS_avgWT = CalculateAverageWT(p_fcfs, n);

    sjf(p_sjf, n);
    SJF_avgWT = CalculateAverageWT(p_sjf, n);

    roundRobin(p_rr, n, tq);
    RR_avgWT = CalculateAverageWT(p_rr, n);

    priorityScheduling(p_ps, n);
    PS_avgWT = CalculateAverageWT(p_ps, n);

    // Compare the algorithms
    cout << "\nComparison of Average Waiting Times:\n";
    cout << "FCFS: " << FCFS_avgWT << " ms\n";
    cout << "SJF: " << SJF_avgWT << " ms\n";
    cout << "Round Robin: " << RR_avgWT << " ms\n";
    cout << "Priority Scheduling: " << PS_avgWT << " ms\n";

    if (FCFS_avgWT <= SJF_avgWT && FCFS_avgWT <= PS_avgWT && FCFS_avgWT <= RR_avgWT) {
        cout << "FCFS has the best average waiting time.\n";
    } 
    else if (SJF_avgWT <= FCFS_avgWT && SJF_avgWT <= PS_avgWT && SJF_avgWT <= RR_avgWT) {
        cout << "SJF has the best average waiting time.\n";
    } 
    else if (RR_avgWT <= FCFS_avgWT && RR_avgWT <= SJF_avgWT && RR_avgWT <= PS_avgWT) {
        cout << "Round Robin has the best average waiting time.\n";
    } 
    else {
        cout << "Priority Scheduling has the best average waiting time.\n";
    }
}

int main() {

    int choice, n, tq;
    while (true) {
        system("cls");
        cout << "--------------------------\n";
        cout << setw(17) << "MENU\n\n";
        cout << "1. Algorithm Simulator\n";
        cout << "2. Algorithm Evaluator\n";
        cout << "3. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        switch (choice) {
            case 1: {
                int subChoice;
                system("cls");
                cout << "-----------------Algorithms-----------------\n";
                cout << "1. First Come First Serve\n";
                cout << "2. Shortest Job First\n";
                cout << "3. Round Robin\n";
                cout << "4. Priority Scheduling\n";
                cout << "5. Back to Main Menu\n";
                cout << "-------------------------------------------\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                system("cls");
                if (subChoice >= 5) {
                    break;
                }
                
                cout << "Enter the number of processes: ";
                cin >> n;
                Process p[n];

                while (n <= 0 || cin.fail()) {
                    
                    cin.clear(); 
                    cin.ignore(); 
                 
                    cout << "Error: The number of process must be greater than 0.\nEnter the number of processes: ";
                    cin >> n;
                }
                if (n <= 0) {
                    cout << "Error: Number of processes must be greater than 0.\nPress Enter to continue.\n";
                    cin.get();
                    cin.get();
                    break;
                }

                InputProcesses(p, n, subChoice == 4);

                switch (subChoice) {
                    case 1:
                        fcfs(p, n);
                        break;
                    case 2:
                        sjf(p, n);
                        break;
                    case 3: {
                        cout << "Enter the Time Quantum: ";
                        cin >> tq;
                        
                        // Input validation loop for Time Quantum
                        while (tq <= 0 || cin.fail()) {

                            cin.clear(); 
                            cin.ignore(); 

                            cout << "Error: Time Quantum must be greater than 0.\nEnter the Time Quantum: ";
                            cin >> tq;
                        }
                        roundRobin(p, n, tq);
                        break;
                    }
                    case 4:
                        priorityScheduling(p, n);
                        break;
                    default:
                        cout << "Invalid choice! Press Enter to continue.\n";
                        break;
                }
                cout << "\nPress Enter to continue.\n";
                cin.get();
                cin.get();
                break;
            }
            case 2:
                system("cls");
                cout << "-----------------Evaluator-----------------\n\n";
                EvaluateSchedulingAlgorithms();
                cout << "Press Enter to continue.\n";
                cin.get();
                cin.get();
                break;

            case 3:
                cout << "\nThe program has been exited............\n";
                return 0;

            default:
                cout << "Invalid choice! Press Enter to continue.\n";
                cin.get();
                cin.get();
        }
    }
    return 0;
}