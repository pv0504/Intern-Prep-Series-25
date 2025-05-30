# Branch Prediction & Pipelining

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

Modern processors achieve high performance through **instruction pipelining** and **branch prediction**. These techniques allow CPUs to execute multiple instructions simultaneously and reduce the performance impact of control flow changes.

- **Pipelining**: Breaking instruction execution into stages that can overlap, increasing throughput.
- **Branch Prediction**: Predicting the outcome of conditional branches to maintain pipeline flow.

Understanding these concepts is essential for computer architecture, compiler optimization, and performance-critical programming interviews.

---

## Explanation of Basic Concepts

### Instruction Pipelining

#### Classic 5-Stage Pipeline (RISC)

1. **IF (Instruction Fetch)**: Fetch instruction from memory
2. **ID (Instruction Decode)**: Decode instruction and read registers
3. **EX (Execute)**: Perform ALU operations or address calculation
4. **MEM (Memory Access)**: Read/write data memory
5. **WB (Write Back)**: Write result back to register

#### Pipeline Benefits

- **Throughput**: Ideally execute one instruction per clock cycle
- **Parallelism**: Multiple instructions in different stages simultaneously
- **Resource Utilization**: Different functional units active concurrently

#### Pipeline Hazards

##### 1. Structural Hazards
- **Cause**: Hardware resource conflicts
- **Example**: Single memory port for both instruction fetch and data access
- **Solution**: Separate instruction and data caches (Harvard architecture)

##### 2. Data Hazards
- **RAW (Read-After-Write)**: Instruction needs result from previous instruction
- **WAR (Write-After-Read)**: Rare in simple pipelines
- **WAW (Write-After-Write)**: Rare in simple pipelines
- **Solutions**: Forwarding/bypassing, pipeline stalls

##### 3. Control Hazards
- **Cause**: Branch instructions change program flow
- **Impact**: Pipeline must be flushed if branch prediction is wrong
- **Solutions**: Branch prediction, delayed branches, branch target buffers

---

### Branch Prediction

#### Static Branch Prediction

##### 1. Always Taken
- **Strategy**: Predict all branches as taken
- **Use Case**: Loops (which typically iterate multiple times)

##### 2. Always Not Taken
- **Strategy**: Predict all branches as not taken
- **Use Case**: Simple implementation, works for forward branches

##### 3. Backward Taken, Forward Not Taken (BTFNT)
- **Strategy**: Backward branches (loops) taken, forward branches not taken
- **Rationale**: Loops iterate, conditionals often fall through

#### Dynamic Branch Prediction

##### 1. One-Bit Predictor
- **Mechanism**: Single bit per branch (taken/not taken history)
- **Problem**: Poor performance on alternating patterns
- **Example**: Mispredicts twice in a loop with one exit

##### 2. Two-Bit Predictor (Bimodal)
- **States**: Strongly Taken (11), Weakly Taken (10), Weakly Not Taken (01), Strongly Not Taken (00)
- **Advantage**: More stable, requires two wrong predictions to change direction
- **Implementation**: 2-bit saturating counter per branch

##### 3. Two-Level Adaptive Predictors

**Global History Predictors**:
- **GAs (Global History, Global Pattern)**: Global branch history indexes global pattern table
- **GAg**: Multiple branches share same pattern table
- **GAp**: Each branch has private pattern table

**Local History Predictors**:
- **PAs (Private History, Global Pattern)**: Each branch has private history, shared pattern table
- **PAg**: Private history, private pattern table

##### 4. Hybrid/Tournament Predictors
- **Mechanism**: Combine multiple predictors with a choice predictor
- **Example**: Alpha 21264 combines local and global predictors
- **Advantage**: Adapts to different branch behavior patterns

#### Advanced Techniques

##### Branch Target Buffer (BTB)
- **Purpose**: Cache branch target addresses
- **Structure**: PC → Target Address mapping
- **Benefit**: Reduces branch penalty by predicting target early

##### Return Address Stack (RAS)
- **Purpose**: Predict return addresses for function calls
- **Mechanism**: Hardware stack that pushes/pops return addresses
- **Accuracy**: Very high for well-structured code

---

## Hands-On Task

### Conceptual

1. Explain why a two-bit predictor performs better than a one-bit predictor for nested loops.
2. Calculate the performance impact of a 20% branch frequency with 95% prediction accuracy and 3-cycle branch penalty.
3. Describe how forwarding reduces pipeline stalls in data hazards.

### Numerical

1. **Pipeline CPI Calculation**:
   - Base CPI = 1.0
   - 20% branches, 10% misprediction rate, 3-cycle penalty
   - 30% loads, 5% cache miss rate, 10-cycle penalty
   - Calculate effective CPI

2. **Branch Predictor Comparison**:
   - Compare one-bit vs two-bit predictor accuracy for pattern: T,T,N,T,T,N,T,T,N...
   - Calculate misprediction rates for each

### Code-based

1. Implement a two-bit branch predictor simulator
2. Create a pipeline simulator showing instruction flow through 5 stages
3. Demonstrate the impact of loop unrolling on branch prediction

---

## Common Pitfalls

- Confusing pipeline depth with performance - deeper pipelines increase branch penalty
- Ignoring the impact of branch frequency on overall performance
- Assuming perfect branch prediction - real predictors have accuracy limits
- Forgetting that pipeline stalls reduce the ideal CPI of 1.0
- Overlooking the interaction between cache misses and pipeline performance
- Mixing up different types of hazards and their solutions
- Assuming branch prediction only affects conditional branches - indirect jumps also matter

---

## Resources

### Reading

- Computer Organization and Design RISC V version, Chapter 4

### Video

- [Computerphile - Pipelining in Computer Architecture](https://www.youtube.com/watch?v=BVNx3wtJ9vs)
- [Computerphile - Branch Prediction](https://www.youtube.com/watch?v=nczJ58WvtYo)

---
