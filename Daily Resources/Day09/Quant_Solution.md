# 💡 Solution: Coins on Chessboard

## 🧩 Problem Overview

We are given an `N x N` board where each cell can either be filled with a coin (1) or left empty (0). We are to count the number of ways to fill the board such that:

- The **sum of each row** is even.
- The **sum of each column** is even.

## 🔍 Observations

### Base Case:
- For a `2 x 2` board, there are exactly **2** valid ways to fill it such that all rows and columns sum to even numbers.

### Next Step:
- For a `3 x 3` board, the number of such valid configurations is **16**.

## 🧠 Insight

Let’s observe the pattern by reducing the problem.

### Key Idea:

For a given `N x N` board:

1. Focus on filling the **top-left (N-1) x (N-1)** portion of the board.
2. Each of these `$(N-1)^2$` cells can independently be filled with a coin or left empty.
3. For **every configuration** of the `(N-1) x (N-1)` board, there is **exactly one unique way** to fill:
   - The rightmost column, and
   - The bottom row,
   
   such that **all rows and all columns** of the full `N x N` board have even sums.

This is because:
- You can adjust the last column to make the row sums even.
- Then, you can adjust the last row to make the column sums even.
- The final cell (bottom-right corner) automatically adjusts itself based on parity.

### 🔄 Reduction Principle:

So, the number of valid ways to fill an `N x N` board reduces to the number of ways to fill a `(N-1) x (N-1)` board **without any parity constraints**.

Each of the `(N−1)^2` cells has **2 choices** (coin or no coin).

Hence, the number of valid configurations is:

## ✅ Final Answer for Chessboard (`8 x 8`)

Here, `N = 8`

So, Ans is $2^49$

## 🧾 Summary

- Break the board into a smaller `(N-1) x (N-1)` board.
- For each configuration of the smaller board, there's a **unique** way to complete the remaining row and column to ensure all sums are even.
- Total ways = `2^((N-1)^2)`

This elegant reduction turns a seemingly hard constraint problem into a simple exponential count.

