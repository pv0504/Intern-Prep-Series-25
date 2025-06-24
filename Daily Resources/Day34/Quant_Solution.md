## ✅ Solution: Same sum subsets

Amy can always divide the numbers into two nonempty disjoint subsets with equal sum. How can you prove it?

Whenever you are asked to show that there are two objects that share a property, you can try to show that there are **more objects than properties**; then, by the **Pigeonhole Principle**, you’re done.

Here, the number of nonempty subsets of Brad’s set of 10 numbers is:

$$
2^{10} - 1 = 1023
$$

The possible subset sums range only from $1$ to:

$$
100 + 99 + \cdots + 91 = \sum_{k=91}^{100} k < 1000
$$

So, there are fewer possible sums than subsets. By the pigeonhole principle, there must be two different subsets with the same sum.

But wait — the problem asked for **disjoint** subsets. That was a red herring!

Throw away the common elements of two sets with equal sums, and you get disjoint subsets with equal sums.

