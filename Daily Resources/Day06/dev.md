# Write-Through vs Write-Back + MESI Protocol

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

When multiple processors or cores access and modify shared memory, ensuring consistency becomes critical. Two key concepts that help manage this are:
- **Write policies**: Which define how and when writes to memory are propagated.
- **Coherence protocols** like **MESI**: Which ensure all cores see a consistent view of memory ie. all cores that have a particular memory address in their caches have the same value stored in them for that memory address.

Understanding these concepts is crucial for systems programming and is frequently tested in architecture-based interviews.

---

## Explanation of Basic Concepts

### Write Policies

#### 1. Write-Through

- **Behavior**: Every write to cache is also written immediately to main memory.
- **Pros**:
  - Simple to implement.
  - Ensures memory always has the latest data (no dirty blocks).
- **Cons**:
  - High memory traffic (each write hits main memory).
  - Slower write performance.

#### 2. Write-Back

- **Behavior**: Writes are done only to the cache. Memory is updated *only when* the block is evicted.
- **Pros**:
  - Reduces memory traffic.
  - Faster write performance (cache-only until eviction).
- **Cons**:
  - Needs dirty bit to track modified blocks.
  - More complex to implement and maintain coherence.

### Write Miss Handling

- **Write-Allocate (Fetch-on-Write)**: On a write miss, load block into cache, then write.
- **No Write-Allocate**: On a write miss, directly write to memory without caching it.

Typical Combinations:
- Write-through → no write-allocate.
- Write-back → write-allocate.

---

### Cache Coherence & The MESI Protocol

MESI stands for:

- **M (Modified)**: Block is only in this cache, and is modified.
- **E (Exclusive)**: Block is only in this cache, and is unmodified.
- **S (Shared)**: Block is in multiple caches, and is unmodified.
- **I (Invalid)**: Block is not valid.

#### MESI State Transitions (Simplified)

| State   | Read (local) | Read (remote) | Write (local) | Write (remote) |
|---------|---------------|----------------|----------------|-----------------|
| I       | → S or E      | —              | → M (fetch)    | —               |
| S       | —             | —              | → M (invalidate others) | → I      |
| E       | —             | → S            | → M            | → I             |
| M       | —             | → S (writeback) | —             | → I (writeback) |

Here state represents the state of a block in a particular cache. Local refers to this particular core and remote refers to any other core. A '-' at any place means no change in state of block in local cache.

---

## Hands-On Task

### Conceptual

1. Explain why write-back is more efficient than write-through in a loop writing to the same array.
2. What happens in MESI when one core writes to a cache line that another core has in Shared state?

### Numerical

1. Given: Write-through with no write-allocate, 20% write misses, memory latency = 50 ns.  
   Estimate the added latency due to writes.
2. Compare memory traffic in write-through vs write-back for a benchmark with frequent repeated writes.

### Code-based

1. Implement a simulation of a cache that supports both write-through and write-back modes.

---

## Common Pitfalls

- Confusing write-through vs write-back behaviors.
- Forgetting about memory traffic — write-through can overwhelm bandwidth.
- Ignoring MESI transitions when analyzing multi-core performance.
- Assuming MESI ensures consistency *across time* — it's for coherence, not memory ordering.

---

## Resources

### Reading

- *Computer Organization and Design* by Patterson & Hennessy (Sections on cache coherence)
- *Computer Architecture A Quantitative Approach* by Hennessy & Patterson (Sections 5.1 to 5.3)
- [Slides on MESI Cache Coherence Protocol](https://drive.google.com/file/d/1uhINTi3bbvHosWyJRykt-qB75epmnjj0/view?usp=sharing)
- [GeeksforGeeks - Write Through vs Write Back](https://www.geeksforgeeks.org/write-through-and-write-back-in-cache/)

### Video

- [Neso Academy - Write Strategies](https://youtu.be/1tvW8kzOpSA?si=2yjEcGssuJ8s6NiA)
- [Neso Academy - Cache Coherence and MESI](https://youtu.be/r_ZE1XVT8Ao?si=8EKFxhZivtBQW7kd)
- [Neso Academy - Snooping Based Cache Coherency Protocols](https://youtu.be/YNpaELJZm2c?si=qBtRJS7PZYALvq72)

---
