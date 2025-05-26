# Cache Hierarchy and Locality

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

Understanding cache hierarchy and locality is fundamental to writing efficient low-level code and is often tested in systems or architecture-oriented intern interviews. These concepts explain how modern CPUs minimize memory latency using fast, intermediate memory layers and leverage patterns in program memory access.

---

## Explanation of Basic Concepts

### Locality of Reference

- **Temporal Locality**: If a memory location is accessed, it is likely to be accessed again soon.
- **Spatial Locality**: If a memory location is accessed, nearby locations are likely to be accessed soon.

### Cache Basics

- **Cache**: A small, fast memory close to the CPU that stores copies of frequently accessed data.
- **Levels**: L1 (smallest and fastest), L2, and L3 (largest and slowest among caches).
- **Why multiple levels?** A single large fast cache is not feasible due to physical and design constraints. Multi-level caches balance speed and capacity.

### Cache Structure
```
Set-Associative Cache Structure

Each row is a Set.
Each column is a Way.
Each block holds multiple words (block size > 1 word).

              Way 0             Way 1             ...         Way (n−1)
          ┌────────────┐    ┌────────────┐                  ┌────────────┐
 Set 0    │ Block 0,0  │    │ Block 0,1  │      ...         │ Block 0,n−1│
          │ (words...) │    │ (words...) │                  │ (words...) │
          ├────────────┤    ├────────────┤                  ├────────────┤
 Set 1    │ Block 1,0  │    │ Block 1,1  │      ...         │ Block 1,n−1│
          │ (words...) │    │ (words...) │                  │ (words...) │
          ├────────────┤    ├────────────┤                  ├────────────┤
  ⋮              ⋮               ⋮            ⋱                   ⋮
 Set (s−1)│Block s−1,0│    │Block s−1,1│      ...         │Block s−1,n−1│
          │ (words...) │    │ (words...) │                  │ (words...) │
          └────────────┘    └────────────┘                  └────────────┘

Legend:
- Each "Set" contains multiple "Ways".
- Each "Block i,j" is the j-th block in set i.
- Each block stores multiple contiguous memory words (Block Size).
- Number of Sets (s) × Number of Ways (n) = Total Cache Blocks.

```

### Cache Mapping Techniques

- **Direct-Mapped**: Each block maps to exactly one location in cache. No. of ways = 1
- **Set-Associative**: Each block maps to a set, and can go into any way within that set.
- **Fully Associative**: A block can be placed anywhere in the cache. No. of sets = 1

### Replacement Policies

- **LRU (Least Recently Used)**: Evicts the block that was used least recently.
- **FIFO (First In First Out)**: Evicts the block that entered the cache earliest.
- **Random**: Evicts a randomly chosen block.

### Performance Metrics

- **Hit**: Data found in cache.
- **Miss**: Data not found; fetched from a lower level or main memory.
- **Miss Rate**: Percentage of accesses that result in a miss.
- **Hit Time**: Time to access cache.
- **Miss Penalty**: Time to fetch data from the next level.
- **Average Memory Access Time (AMAT)**:  
  `AMAT = Hit Time + (Miss Rate x Miss Penalty)`

### Inclusive vs Exclusive Caches

- **Inclusive**: All data in L1 is also present in L2.
- **Exclusive**: Data exists in only one level at a time to maximize total capacity.

---

## Hands-On Task

Try to solve the following:

### Conceptual

1. Explain why spatial locality makes iterating over a 2D array row-wise faster than column-wise.
2. Compare cache hit rates for direct-mapped vs 2-way set associative caches given a specific access sequence.

### Numerical

1. Given: Hit time = 1 ns, Miss rate = 5%, Miss penalty = 50 ns.  
   Compute AMAT.
2. Simulate a sequence of memory accesses under direct-mapped and set-associative caches, and count the hits and misses.

### Code-based

1. Write a C++ program that performs matrix multiplication and measure its performance. Then, try optimizing loop order to improve cache locality.
2. Simulate a basic direct-mapped cache in code and track hit/miss counts.

---

## Common Pitfalls

- Ignoring spatial locality in nested loops or data structures.
- Assuming more associativity is always better - it increases access time.
- Misunderstanding inclusive vs exclusive cache hierarchies.
- Forgetting unit conversions when calculating AMAT.
- Using large structures on the stack (could overflow or perform poorly due to caching effects).

---

## Resources

### Reading

- *Computer Organization and Design* by Patterson & Hennessy (Chapters on Memory Hierarchy)
- [GeeksforGeeks - Cache Memory](https://www.geeksforgeeks.org/cache-memory-in-computer-organization/)
- [CMU 15-213 Lecture Notes on Caching](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f15/www/lectures.html)

### Video

- [David Black Schaffer's videos on Caches](https://www.youtube.com/@davidblack-schaffer1906/featured)
- [Neso Academy - Cache Memory (YouTube Playlist)](https://youtube.com/playlist?list=PLBlnK6fEyqRg6Y2y4dJNRm3q3q3tU5aYh)
- [Computerphile - How CPU Caches Work](https://www.youtube.com/watch?v=vA7PZ4b3Ce4)
- [Gate Smashers - Cache Mapping Techniques](https://www.youtube.com/watch?v=7A5y3jN3QvU)

---
