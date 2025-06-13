# CPU Scheduling Algorithm Simulator and Evaluator

## 📋 Project Overview

This project is a **C++ console-based simulator** that implements and compares four classical CPU Scheduling Algorithms:
- **First-Come-First-Serve (FCFS)**
- **Shortest Job First (SJF)**
- **Round Robin (RR)**
- **Priority Scheduling**

It allows the user to:
- Input process details such as **Burst Time**, **Priority**, and **Time Quantum** (for Round Robin).
- Simulate each scheduling algorithm separately.
- Evaluate all algorithms to find which one yields the **lowest average waiting time**.
- Visualize scheduling through a **Gantt Chart**.


---


## 🚀 Key Features

- ✅ **Multiple Algorithms Supported:**
  - First-Come-First-Serve (FCFS)
  - Shortest Job First (SJF)
  - Round Robin (RR)
  - Priority Scheduling
- ✅ **User-Friendly Menu-Based Interface**
- ✅ **Gantt Chart Visualization**
- ✅ **Performance Metrics Calculation**
  - Waiting Time
  - Turnaround Time
  - Average Waiting Time
- ✅ **Best Algorithm Evaluation**
- ✅ **Robust Input Validation & Error Handling**

---

## 🏗️ Project Structure & Explanation

### 1. Process Structure (Data Representation)

Defined using a `struct`:
- `pid`: Process ID
- `burstTime`: CPU burst time
- `waitingTime`: Time spent waiting in the ready queue
- `turn_around_time`: Total time from arrival to completion
- `priority`: Process priority (lower value = higher priority)
- `remaining`: Used in Round Robin to track remaining burst time
- `starting_time`: Not used
- `completion_time`: Not used

---

### 2. Main Functionalities

- **InputProcesses()**:  
  Collects process data from the user and validates the input.

- **CalculateAverageWT()**:  
  Calculates the average waiting time of processes.

- **DisplayResults()**:  
  Shows a table summary with PID, Burst Time, Waiting Time, and Average Waiting Time.

- **DisplayGanttChart()**:  
  Displays a simple Gantt Chart indicating process execution order and timing.

- **CPU Scheduling Algorithms**:  
  - `fcfs()`: First-Come-First-Serve  
  - `sjf()`: Shortest Job First  
  - `roundRobin()`: Round Robin  
  - `priorityScheduling()`: Priority Scheduling  

- **EvaluateSchedulingAlgorithms()**:  
  Runs all four algorithms, calculates their average waiting times, and displays which performs best.

---
