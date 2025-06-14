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


## ⚙️ How to Run the Project

1. Compile the program using:

   ```bash
   g++ Cpu_Scheduling_Project.cpp -o scheduler
   ```
   - If you are running it in VS Code, you can simply use the 'Run Code' option.

2. **Run the executable** using:
   ```bash
   ./scheduler

3. **From the Main Menu, select:**

   * **Algorithm Simulator**
   * **Algorithm Evaluator**
   * **Exit**

### 🔸 **If you choose Option 1 (Algorithm Simulator):**

* Pick an algorithm to simulate (FCFS, SJF, RR, Priority).
* Enter:

  * Number of processes.
  * **Burst Time** for each process.
  * **Priority** (only if Priority Scheduling).
  * **Time Quantum** (only if Round Robin).

### 🔸 **If you choose Option 2 (Algorithm Evaluator):**

* Enter:

  * Number of processes.
  * **Burst Time**, **Priority**, and **Time Quantum**.
* Program will:

  * Run all algorithms.
  * Show Gantt Charts and results.
  * Compare average waiting times and suggest the best algorithm.

---


## 🧑‍💻 Main Menue

- Main Menue Options:

![Image](https://github.com/user-attachments/assets/eb8e6a33-7d40-42d0-bc9a-e40a1d80e081)

- Inside the Algorithm Simulator Menue: 

![Image](https://github.com/user-attachments/assets/de197a95-294d-4878-abef-347e93751ac7)

---

## 📤 Example Outputs

-  First Come First Serve (FCFS) Scheduling

![Image](https://github.com/user-attachments/assets/c886ae71-bae8-43d4-bfa5-1f03d18a1e39)

- Shortest Job First (SJF) Scheduling

![Image](https://github.com/user-attachments/assets/058e84f0-8cbe-45d0-ba43-d8a18fd79ebc)

- Round Robin (RR) Scheduling

![Image](https://github.com/user-attachments/assets/2bc85bea-f097-4bb2-a86a-18f79b08ec75)

- Priority Scheduling

![Image](https://github.com/user-attachments/assets/4938adbb-0b72-49aa-867b-3db06d9f2424)

- Inside the Algorithm Evaluator Menu

![Image](https://github.com/user-attachments/assets/036f8c32-e7e6-4e09-8507-c8094c392d77)

![Image](https://github.com/user-attachments/assets/f1913faf-8108-4863-a468-8141d38d3ffd)

---

## 🎯 **Project Assumptions**

* All inputs (Burst Time, Priority, Time Quantum) are **positive integers**.
* **Non-preemptive** versions of SJF and Priority Scheduling are used.
* **Stable sorting**: If two processes have the same burst time or priority, their order remains as per user input.

---

## ⚠️ **Limitations**

* Not designed for **very large datasets** (e.g., thousands of processes).
* **Basic Gantt Chart**: Does not visualize state changes or preemption details.

---

## 📄 **References**

* Operating System Concepts by Abraham Silberschatz
* C++ Standard Library
* East West University CSE325 - Operating Systems Course Materials

---

## 🤝 Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository, make changes, and submit a pull request.

---

## 🔒 License

This project is licensed under the [**MIT License**](https://opensource.org/licenses/MIT).

---

## 📬 Contact

If you have any questions or concerns, please don't hesitate to contact me via email at <a href="mailto:imam220826@gmail.com">imam220826@gmail.com</a>

