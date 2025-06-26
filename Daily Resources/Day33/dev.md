# Virtual Memory + Paging

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

Virtual memory is one of the most fundamental concepts in modern operating systems and computer architecture. It provides:
- **Memory abstraction**: Each process gets its own virtual address space.
- **Memory protection**: Processes cannot access each other's memory.
- **Memory management**: Efficient use of physical memory through demand paging.

Key concepts include:
- **Virtual addresses vs Physical addresses**: Translation between program addresses and actual RAM locations.
- **Paging**: Dividing memory into fixed-size blocks for efficient management.
- **Page tables**: Data structures that map virtual pages to physical frames.
- **TLB (Translation Lookaside Buffer)**: Hardware cache for address translations.

---

## Explanation of Basic Concepts

### Virtual Memory Basics

#### Address Translation
- **Virtual Address (VA)**: Address used by programs (what CPU generates).
- **Physical Address (PA)**: Actual address in physical memory (RAM).
- **Memory Management Unit (MMU)**: Hardware that translates VA to PA.

#### Why Virtual Memory?
- **Isolation**: Each process has its own address space (security).
- **Simplification**: Programs can assume they have entire memory.
- **Efficiency**: Only load needed parts of programs into RAM.
- **Protection**: Control access permissions (read/write/execute).

---

### Paging System

#### Basic Paging Concepts
- **Page**: Fixed-size block of virtual memory (typically 4KB).
- **Frame**: Fixed-size block of physical memory (same size as page).
- **Page Table**: Maps virtual page numbers to physical frame numbers.
- **Page Table Entry (PTE)**: Contains frame number + control bits.

#### Page Table Entry Structure
```
| Present | Dirty | Referenced | Permissions | Frame Number |
|    1    |   1   |     1      |     3       |      20      |
```

Common bits:
- **Present (P)**: Page is in physical memory.
- **Dirty (D)**: Page has been modified.
- **Referenced (A)**: Page has been accessed recently.
- **Permissions**: Read/Write/Execute permissions.

---

### Address Translation Process

#### Two-Level Address Translation
For 32-bit systems with 4KB pages:
```
Virtual Address (32 bits):
| Page Number (20 bits) | Offset (12 bits) |

Physical Address (32 bits):
| Frame Number (20 bits) | Offset (12 bits) |
```

#### Multi-Level Page Tables
- **Problem**: Large page tables (1M entries for 32-bit).
- **Solution**: Hierarchical page tables (2-level, 3-level, 4-level).
- **x86-64**: 4-level paging (PML4 → PDP → PD → PT).

```
48-bit Virtual Address (x86-64):
| PML4 (9) | PDP (9) | PD (9) | PT (9) | Offset (12) |
```

---

### Translation Lookaside Buffer (TLB)

#### TLB Basics
- **Purpose**: Cache recent VA→PA translations.
- **Location**: Inside CPU (very fast access).
- **Size**: Small (64-512 entries typically).
- **Associativity**: Fully associative or set-associative.

#### TLB Hit vs Miss
- **TLB Hit**: Translation found in TLB (fast, 1-2 cycles).
- **TLB Miss**: Must walk page table (slow, 10-100+ cycles).
- **TLB Miss Handling**: Hardware vs Software managed.

---

### Demand Paging & Page Replacement

#### Demand Paging
- **Concept**: Load pages only when accessed (lazy loading).
- **Page Fault**: Exception when accessing non-present page.
- **Page Fault Handling**:
  1. OS finds free frame or evicts a page.
  2. Load page from storage into frame.
  3. Update page table.
  4. Restart instruction.

#### Page Replacement Algorithms
- **FIFO**: Replace oldest page.
- **LRU (Least Recently Used)**: Replace least recently accessed.
- **Clock/Second Chance**: Approximation of LRU using reference bit.
- **Optimal**: Replace page used furthest in future (theoretical).

#### Working Set & Thrashing
- **Working Set**: Set of pages process actively uses.
- **Thrashing**: System spends more time paging than executing.
- **Causes**: Too many processes, insufficient memory.

---

## Hands-On Task

### Conceptual

1. Explain why virtual memory enables multiprogramming even when total program sizes exceed physical memory.
2. Why do modern systems use multi-level page tables instead of single-level?

### Numerical

1. **Address Translation**: Given a 32-bit system with 4KB pages:
   - Virtual address: 0x12345678
   - Calculate page number and offset
   - If page table entry contains frame number 0x789, what's the physical address?

2. **TLB Performance**: System with:
   - TLB hit time: 2 ns
   - Memory access time: 100 ns  
   - TLB hit rate: 95%
   - Calculate effective memory access time

3. **Page Table Size**: Calculate page table size for:
   - 64-bit virtual address space
   - 4KB pages
   - 8-byte PTEs
   - Single-level vs 4-level page tables

### Code-based

1. Implement a simple page table simulator that:
   - Translates virtual addresses to physical addresses
   - Handles page faults
   - Simulates TLB with LRU replacement

2. Write a program that demonstrates:
   - Memory access patterns and their effect on TLB performance
   - Page fault behavior with demand paging

---

## Common Pitfalls

- **Confusing virtual vs physical addresses** — Remember programs use virtual addresses.
- **Ignoring TLB impact** — TLB misses can severely impact performance.
- **Forgetting page alignment** — Pages/frames are aligned to page boundaries.
- **Assuming infinite memory** — Page replacement is crucial when memory is full.
- **Mixing up page sizes** — Different architectures use different page sizes (4KB, 2MB, 1GB).
- **Not considering memory protection** — Virtual memory provides isolation and security.
- **Overlooking cache effects** — Virtual vs physical caches have different coherence issues.

---

## Resources

### Reading

- Section 5.7 of *Computer Organization and Design RISC-V Edition* by Hennesy and Patterson

### Video

- [David Black Schaffer's videos on virtual memory](https://www.youtube.com/playlist?list=PLiwt1iVUib9s2Uo5BeYmwkDFUh70fJPxX)
- [MIT 6.004 - Virtual Memory](https://www.youtube.com/watch?v=8yO2FBBfaB0)
- [Computerphile - Virtual Memory](https://www.youtube.com/watch?v=5lFnKYCZT5o)

---
