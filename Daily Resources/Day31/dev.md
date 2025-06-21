# Scheduling + Starvation/Aging - One Day Study Guide

## What You'll Learn Today

### Core Concepts
- **CPU Scheduling**: How operating systems decide which process gets CPU time
- **Scheduling Algorithms**: Different strategies for process scheduling
- **Starvation**: When processes never get CPU time
- **Aging**: Technique to prevent starvation by gradually increasing process priority

### Key Scheduling Algorithms
- First Come First Served (FCFS)
- Shortest Job First (SJF)
- Priority Scheduling
- Round Robin (RR)
- Multilevel Queue Scheduling
- Multilevel Feedback Queue

### Starvation & Aging Specifics
- What causes starvation in different scheduling algorithms
- How aging mechanism works
- Implementation strategies for aging
- Trade-offs between fairness and efficiency

## How to Learn

### 1. Conceptual Understanding
- Start with basic scheduling concepts and terminology
- Understand the scheduling problem and why it matters
- Learn each algorithm's logic and characteristics
- Focus on when starvation occurs and why

### 2. Visual Learning
- Draw Gantt charts for different scheduling scenarios
- Trace through algorithm execution step by step
- Visualize how aging affects process priorities over time
- Compare algorithm performance with diagrams

### 3. Problem Solving
- Work through scheduling examples with different algorithms
- Calculate waiting time, turnaround time, and response time
- Identify starvation scenarios in given process sets
- Design aging solutions for specific problems

## Learning Resources

### Primary Resources
- **Operating System Concepts (Silberschatz)** - Chapter 5: CPU Scheduling
- **Modern Operating Systems (Tanenbaum)** - Chapter 2: Processes and Threads
- **Operating Systems: Three Easy Pieces** - Free online book, Scheduling chapters

### Online Resources
- **GeeksforGeeks OS Scheduling** - Comprehensive tutorials with examples
- **YouTube: Neso Academy** - OS scheduling playlist with visual explanations
- **Coursera/edX** - Operating Systems courses (audit for free)
- **Wikipedia** - Good for quick algorithm references

### Interactive Tools
- **OS Scheduling Simulator** - Online tools to visualize algorithms
- **Process Scheduling Visualizer** - Step-by-step algorithm execution
- **University lab simulators** - Many CS departments have public tools

## Hands-On Tasks

### Task 1: Algorithm Implementation & Analysis
**Objective**: Implement and compare scheduling algorithms

**What to do**:
- Create a simple scheduler simulator (use any programming language)
- Implement FCFS, SJF, Priority, and Round Robin algorithms
- Test with the same set of processes: P1(burst=10, priority=3), P2(burst=1, priority=1), P3(burst=2, priority=4), P4(burst=1, priority=5), P5(burst=5, priority=2)
- Calculate and compare average waiting time and turnaround time for each algorithm
- Identify which processes face starvation in priority scheduling

**Expected outcome**: Understanding of how different algorithms perform and behave

### Task 2: Aging Mechanism Design
**Objective**: Implement aging to solve starvation

**What to do**:
- Take the priority scheduling from Task 1 where starvation occurs
- Implement an aging mechanism that increases priority of waiting processes
- Test different aging rates (e.g., increase priority by 1 every 5 time units)
- Document how aging affects the scheduling order and eliminates starvation
- Experiment with different aging strategies and compare results

**Expected outcome**: Practical understanding of how aging prevents starvation

## Key Formulas & Metrics

### Performance Metrics
- **Turnaround Time** = Completion Time - Arrival Time
- **Waiting Time** = Turnaround Time - Burst Time
- **Response Time** = First CPU allocation - Arrival Time
- **Average Waiting Time** = Sum of all waiting times / Number of processes

### Aging Formula (Common Implementation)
```
New Priority = Old Priority - (Waiting Time / Aging Factor)
```

## Quick Reference

### When Starvation Occurs
- **Priority Scheduling**: Low priority processes may never execute
- **SJF**: Long processes may wait indefinitely
- **Multilevel Queue**: Lower level queues may starve

### Aging Benefits
- Ensures all processes eventually get CPU time
- Maintains relative priority ordering initially
- Configurable aging rate for different system needs

### Common Aging Implementations
- **Linear Aging**: Priority decreases by constant amount over time
- **Exponential Aging**: Priority changes exponentially with waiting time
- **Threshold Aging**: Priority changes only after certain waiting time

## Success Indicators

By the end of today, you should be able to:
- Explain how each major scheduling algorithm works
- Identify starvation scenarios in scheduling problems
- Design and implement basic aging mechanisms
- Calculate scheduling performance metrics
- Compare trade-offs between different scheduling approaches
- Understand real-world applications of these concepts

## Next Steps (Optional)
- Explore advanced scheduling in modern OS (Linux CFS, Windows scheduler)
- Study real-time scheduling algorithms
- Learn about multiprocessor scheduling
- Investigate scheduling in distributed systems
