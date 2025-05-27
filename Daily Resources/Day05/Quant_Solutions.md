# Level 1: Candy Circle

The maximum number of candies held by a single student can never increase.

The minimum number of candies held by a single student always strictly increases, unless the student to his right also has the minimum number of candies, in which case the length of the longest consecutive segment of students who have minimum number of candies strictly decreases. Thus eventually the minimum has to strictly increase.

Since the minimum has to strictly increase in a finite number of steps and cannot go beyond the maximum, all the numbers must eventually be equal in at most $n(\text{max} - \text{min})$ steps.

---

# Level 2: Chef's Delight

It is possible even if there are $2^n$ dishes and you want to find a list of $n$ dishes: we prove this by induction on $n$. It's pretty obvious when $n = 1$.

Assume it holds for $n - 1$. When there are $2^n$ dishes, imagine holding a tournament, where every pair of dishes faces off, and the winner is the one whom more participants prefer. There will be no ties as there are an odd number of participants, so there will be

$$
\binom{2^n}{2}
$$

victories total.

This means that some dish must have had at least $2^{n-1} - 1$ victories, because if everyone had less than this, the total number of victories would be at most

$$
2^n \cdot (2^{n-1} - 2)
$$

which is less than $\binom{2^n}{2}$.

Now simply, select a dish with $2^{n-1} - 1$ victories, remove that dish, along with the $2^{n-1} - 1$ dishes it beats.

What remains are $2^{n-1}$ dishes; by induction, we can find a list of length $n - 1$ which works for these remaining dishes. Then adding this dish described by this method to our menu recursively creates a list of length $n$ which works for all $2^n$ dishes.

which is less than $\binom{2^n}{2}$.

Now simply, select a dish with $$(2^{n-1} - 1)$$ victories, remove that dish, along with the $$(2^{n-1} - 1 )$$ dishes it beats.

What remains are $$( 2^{n-1} )$$ dishes; by induction, we can find a list of length $$( n - 1 )$$ which works for these remaining dishes. Then adding this dish described by this method to our menu recursively creates a list of length $$( n )$$ which works for all $$( 2^n )$$ dishes.
