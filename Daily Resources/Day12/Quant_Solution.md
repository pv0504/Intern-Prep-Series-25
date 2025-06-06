## Solution : Constrained Subsets

These puzzles can all be tackled the same way. The idea is to try to cover the numbers from 1 to 30 by bunches of numbers with the property that from each bunch, you can only take one number for inclusion in your subset. Then, if you can construct a subset that consists of one choice from each bunch, you have yourself a maximum-sized subset.

### Square-Free Case

In the first case, fix any number `k` which is square-free (in other words, its prime factorization contains at most one copy of each prime). Now look at the set `Sₖ` you get by multiplying `k` by all possible perfect squares.

If you take two numbers, say `k·x²` and `k·y²`, from `Sₖ`, then their product is
`k²·x²·y² = (k·x·y)²`
so they can’t both be in our subset. On the other hand, two numbers from different `Sₖ`’s cannot have a square product since one of the two `k`’s will have a prime factor not found in the other, and that factor will appear an odd number of times in the product.

Now, every number is in just one of these sets `Sₖ` — given `n`, you can recover the `k` for which `n ∈ Sₖ` by multiplying together one copy of each prime that appears with an odd exponent in the factorization of `n`. Between 1 and 30, the choices for `k` (i.e., the square-free numbers) are
`1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 2×3, 2×5, 2×7, 2×11, 2×13, 3×5, 3×7`, and finally `2×3×5`: **19 in all**.
You can choose each `k` itself as the representative from `Sₖ`, so a subset of size **19** is achievable and best possible.

### No One Divides Another Case

To avoid one number dividing another evenly, note that if you fix an odd number `j`, then in the bunch `Bⱼ = {j, 2j, 4j, 8j, ...}` — that is, `j` times the powers of 2 — you can only take one. If you take for your subset the top half of the numbers from 1 to 30, namely **16 through 30**, you have got one from each `Bⱼ`, and of course no member of this subset divides another evenly since their ratios are all less than 2.
So the **15 numbers** you get this way is best possible.

### Relatively Prime Case

Finally, to get a maximum-sized subset all of whose members are relatively prime, you naturally want to look at bunches consisting of all multiples of a fixed prime `p`. You can take `p` itself as the representative of its bunch, so you can do no better than to take as your subset all the **primes below 30**, plus the number **1** itself, for a total of **11 members**.

---
