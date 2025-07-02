# `mmap` + `sbrk` for Memory Allocation

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

Memory allocation is a core part of how programs run on modern operating systems. System calls like `mmap` and `sbrk` allow programs to request memory directly from the kernel. They underpin dynamic memory management in `malloc`, garbage collectors, and custom allocators.

Key concepts include:
- **Heap allocation** using `sbrk` (traditional, linear)
- **Anonymous memory mapping** with `mmap` (modern, flexible)
- **Hybrid allocation strategies** in real-world memory allocators (e.g., glibc `malloc`)

---

## Explanation of Basic Concepts

### Memory Allocation Basics

#### Heap
- Area of memory used for dynamic allocation (e.g., via `malloc`).
- Grows upward from the end of the data segment.
- Traditionally managed via `sbrk`.

#### `sbrk` (Heap Expansion)
- Increases or decreases the **program break** (end of the heap).
- Suitable for simple, linear memory growth.
- Used by older implementations of `malloc`.

```c
void *current_break = sbrk(0); // get current program break
sbrk(4096);                    // increase heap by 4KB
```

#### `mmap` (Anonymous Mapping)
- Maps pages of memory anywhere in virtual address space.
- Supports more flexible and scalable memory management.
- Common for large allocations, or when memory needs alignment/guard pages.

```c
void *p = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
```

---

### How Allocators Use `sbrk` and `mmap`

| Allocation Size | Allocator Behavior                  |
|-----------------|-------------------------------------|
| Small (<128KB)  | Use `sbrk()` to extend heap         |
| Large (≥128KB)  | Use `mmap()` for separate regions   |

#### Why Both?
- `sbrk` is efficient for small, frequent allocations.
- `mmap` avoids heap fragmentation and supports flexible memory reuse.

#### Example: `malloc`
- Glibc `malloc` uses:
  - `sbrk` for small, heap-style allocations.
  - `mmap` for large blocks and thread-local arenas.

---

### Memory Layout with `sbrk` and `mmap`

```
+---------------------+
| Text Segment        | ← Code
+---------------------+
| Data Segment        | ← Global/static vars
+---------------------+
| Heap (sbrk)         | ← Grows upward
+---------------------+
|                     |
| ... (Unused)        |
|                     |
+---------------------+
| mmap allocations     | ← Scattered anywhere in address space
+---------------------+
| Stack               | ← Grows downward
+---------------------+
```

---

## Hands-On Task

### Conceptual

1. **Why is `mmap` preferred over `sbrk` for large allocations?**
2. **What are the disadvantages of relying solely on `sbrk`?**
3. **Why can `mmap` coexist more easily with threads or memory pools?**

### Numerical

1. **Memory Growth**:
   - Initial break: `0x10000000`
   - Call `sbrk(8192)`
   - New break address?

2. **Page alignment with `mmap`**:
   - You request `5000` bytes via `mmap`.
   - How much memory will actually be mapped (assuming 4KB pages)?

3. **Allocator split**:
   - If malloc uses `sbrk` below 128KB and `mmap` above:
     - Which syscall is used for `malloc(200000)`?

### Code-based

1. **Use `sbrk` to build a custom allocator**:
   - Allocate 4KB chunks from the heap.
   - Track free space using a simple bump allocator.

2. **Use `mmap` to implement a large allocator**:
   - Allocate anonymous memory blocks.
   - Write/read to the memory to ensure it’s accessible.

3. **Compare** performance and layout of:
   - `malloc(64)` → likely uses `sbrk`
   - `malloc(256 * 1024)` → likely uses `mmap`

---

## Common Pitfalls

- **Mixing `sbrk` and `mmap` arbitrarily** — They allocate from different parts of memory; managing overlap is unsafe.
- **Assuming heap is contiguous** — `mmap` allocations can be scattered.
- **Forgetting page alignment** — `mmap` always allocates in multiples of the page size (commonly 4KB).
- **Memory leaks** — You must `munmap` what you `mmap`, just like `free`ing `malloc`.
- **Ignoring protection flags** — `mmap` needs correct `PROT_READ`, `PROT_WRITE`, etc.
- **Thread safety** — `sbrk` modifies a global break, which can conflict across threads if misused.

---

## Resources

### Video

- [How processes get more memory. (mmap, brk) (Jacob Sorber)](https://m.youtube.com/watch?v=XV5sRaSVtXQ)
- [sbrk/brk System Calls and Optimistic Allocation Explained (Richard Habeeb)](https://m.youtube.com/watch?v=vEXRpiI4Dhk)

