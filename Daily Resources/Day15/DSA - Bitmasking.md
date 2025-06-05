# 🔐 DSA Problem of the Day – Bitmasking Special (DD/MM/2025)

### 🎯 Focus: Mastering Bitmasking in Competitive Programming

Bitmasking is a powerful technique used to solve problems involving subsets, state compression, combinatorics, dynamic programming, and optimization. It is essential for performance-efficient code in contests and interviews.

---

## 📚 Learning Resources

### 📌 Bitmasking Basics  
Understand binary representation, bit operations, and how they apply to sets and states.

- [Bit Manipulation – GeeksforGeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [Bitmasking Introduction – CP-Algorithms](https://cp-algorithms.com/algebra/bitwise-operations.html)
- [Bitmasking Tutorial – Codeforces EDU](https://codeforces.com/edu/course/2/lesson/2)
- 📘 Competitive Programmer’s Handbook – Chapter on Bit Operations

---

## 🧮 Must-Know Bitwise Operations

| Operation     | Syntax           | Description                        |
|--------------|------------------|------------------------------------|
| AND          | a & b          | 1 only if both bits are 1          |
| OR           | a | b          | 1 if either bit is 1               |
| XOR          | a ^ b          | 1 if bits are different            |
| NOT          | ~a             | Inverts bits                       |
| Left Shift   | a << n         | Multiplies a by 2^n            |
| Right Shift  | a >> n         | Divides a by 2^n               |
| Check Bit    | (a >> i) & 1   | Checks if the i-th bit is set     |
| Set Bit      | a | (1 << i)   | Sets the i-th bit                 |
| Clear Bit    | a & ~(1 << i)  | Clears the i-th bit               |
| Toggle Bit   | a ^ (1 << i)   | Flips the i-th bit                |

---

## 🧠 Common Use-Cases of Bitmasking

- Generating all subsets of a set  
- State representation in DP  
- Efficient set operations  
- Optimization over small constraints (e.g., n ≤ 20)  
- Solving puzzles and games (e.g., TSP, Lights Out)  
- Building solutions from *MSB to LSB* under constraints

---

## 🧩 Practice Problems (Increasing Difficulty)

### 🟢 Easy – Learn the Basics

1. [Subsets – Leetcode 78](https://leetcode.com/problems/subsets/)  
   📌 Generate all subsets using bitmask.

2. [Two Sets – CSES](https://cses.fi/problemset/task/1092/)  
   📌 Partition the set into two equal-sum subsets.

3. [Bit Manipulation – HackerEarth](https://www.hackerearth.com/practice/notes/bit-manipulation/)  
   📌 Try problems at the end of this tutorial.

---

### 🟡 Medium – Algorithmic Thinking

4. [Apple Division – CSES](https://cses.fi/problemset/task/1623/)  
   🧠 Subset sum minimization using bitmask.

5. [TSP – Traveling Salesman Problem – CSES](https://cses.fi/problemset/task/1690/)  
   🧠 Classic DP with bitmask: dp[mask][i] = min(...).

6. [Codeforces 1037C – Equalize](https://codeforces.com/problemset/problem/1037/C)  
   🧠 Understand greedy and bit-level manipulation.

---

### 🔴 Hard – Bitmask DP / Constraint Construction

7. [Matching – AtCoder Educational DP Contest (Task O)](https://atcoder.jp/contests/dp/tasks/dp_o)  
   📌 Count number of perfect matchings using bitmask DP.

8. [Codeforces 2085C – Computer Game](https://codeforces.com/problemset/problem/2085/C)  
   🧠 Bit-level state building under lexicographical constraints.

9. [Codeforces 2035C – Game with Multiset](https://codeforces.com/problemset/problem/2035/C)  
   🧠 Construct a number step-by-step from MSB to LSB under XOR-based restrictions.

---

## 🧰 Tips & Tricks

- 2^n is always greater than the sum of all smaller powers of 2:  
  \[
  2^n > 2^0 + 2^1 + ... + 2^{n-1}
  \]

- Identity: x ^ x = 0 for any integer x. This is frequently used to cancel out values.

- Use __builtin_popcount(mask) in C++ to count number of set bits in a mask.

- Represent subsets of a size-n set using masks from 0 to (1 << n) - 1.

- Think of bitmasks as binary arrays — AND/OR/XOR operations model subset logic, toggling, and conditional selection.

---

## 📢 Note

Solutions and explanations will be released on *06/06/2025*. Make sure to try them out yourself before that!

> 📞 For any doubts, reach out to me at *9873886151*  
> 🧠 Happy Bitmasking! 🚀
