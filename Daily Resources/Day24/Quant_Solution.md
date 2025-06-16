
## ✅ Solution: Adding, Multiplying, and Grouping

This has a pigeonhole flavor, though not in the most obvious way.

One million is $2^6 \cdot 5^6$, and 42 equals $6 \cdot 2 + 6 \cdot 5$.
So we can split the 42 numbers into **six groups of 2** and **six groups of 5**, with multiplication between groups.

If each group of 2 gives an even number, and each group of 5 gives a multiple of 5, their product will be divisible by $2^6 \cdot 5^6$.

**For the 2-sized groups**:

* If both numbers are even or both are odd, add them.
* If one is even and one is odd, multiply them.
  Either way, the result is even.

**For the 5-sized groups**:
We want a subset of the five numbers that sums to a multiple of 5.

Let the group be $n_1, n_2, ..., n_5$ and define partial sums
$s_i = n_1 + ... + n_i$, then consider $r_i = s_i \mod 5$.

* If any $r_i = 0$, then the prefix sum is divisible by 5.
* If not, the 5 $r_i$'s lie in {1, 2, 3, 4}. By pigeonhole, two must be equal.
* Say $r_i = r_j$, then $s_j - s_i = n_{i+1} + ... + n_j$ is divisible by 5.

So in every group of 5, we can find a nonempty consecutive subsequence whose sum is divisible by 5 — and multiply that with the rest.

This proves the expression can be constructed to be divisible by one million.



