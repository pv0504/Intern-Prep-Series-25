### ✅ Solution

The player who plays **first always wins**.

Suppose A is playing first. If A already has a winning strategy, we're done.

Assume A doesn't have a winning strategy. Then B has one, **no matter what A picks** on the first move.

Now suppose A removes just the number **1** in their first move.

If B has a winning strategy from here, then they would have picked some number **x** next.

But if A had picked **x** instead of 1 in the first move, then **x** and all its divisors (including 1) would have been removed. In other words, A would have effectively carried out B's winning move **before B could**, thus turning B's winning strategy into A’s — which contradicts the assumption that A didn't have a winning strategy.

Therefore, the assumption that B has a winning strategy must be false.

✅ **Conclusion**: The first player **always has a winning strategy**, regardless of N.

---
