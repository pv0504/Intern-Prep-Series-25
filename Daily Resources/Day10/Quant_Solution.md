## Solution: Faulty Number Lock 

Often the easiest way to tackle a problem of this sort is geometrically. The space of all possible combinations is an $8 \times 8 \times 8$ combinatorial cube, and each time you try a combination, you cover all combinations on the three orthogonal lines which intersect at that point.

Once you see the problem this way, you are likely to discover that the best way to cover all the points in the cube is to concentrate all your test points in just two of the eight $4 \times 4 \times 4$ octants. You will then arrive at a solution equivalent to the one described below.

Try all combinations with numbers from $\{1, 2, 3, 4\}$ whose sum is a multiple of 4; there are 16 of those, since if you pick the numbers on the first two (or any two) of the dials, the number on the third is determined. Now try all the combinations you get by adding $(4, 4, 4)$, that is, by adding 4 to each of the three numbers; there are 16 more of those, and we claim that together the 32 choices cover all possibilities.

It is easy to see that this works. The correct combination must have either two (or more) values in the set $\{1, 2, 3, 4\}$, or two or more values in the set $\{5, 6, 7, 8\}$. If the former is the case, there is a unique value for the third dial (the one whose number may not be among $\{1, 2, 3, 4\}$) such that the three were among the first 16 tested combinations. The other case is similar.

---

### Proving that 32 combinations is optimal (Hard)

To see that we can’t cover with 31 or fewer test-combinations, suppose that $S$ is a cover and $|S| = 31$. Let  
$S_i = \{(x, y, z) \in S : z = i\}$  
be the $i$ th level of $S$.

Let $A = \{1, 2, 3\}$, $B = \{4, 5, 6, 7, 8\}$, and $C = \{2, 3, 4, 5, 6, 7, 8\}$. At least one level of $S$ must contain 3 or fewer points; we might as well assume $S_1$ is this level and $|S_1| = 3$. (If $|S_1| \leq 2$, there’s an easy contradiction.) The points of $S_1$ must lie in a $3 \times 3 \times 1$ subcube; we may assume that they lie in $A \times A \times \{1\}$.

The 25 points in $B \times B \times \{1\}$ must be covered by points not in $S_1$. No two of them can be covered by the same point in $S$, thus, $S \setminus S_1$ (that is, the elements of $S$ that are not in $S_1$) has a subset $T$ of size 25 that lies in the subcube $B \times B \times C$.

Now consider the set  
$P = \{(x, y, z) : z \in C, (x, y, 1) \notin S_0, (x, y) \notin B \times B\}$.  
A quick count shows that  
$$|P| = (64 - 3 - 25) \times 7 = 252.$$

The points in $P$ are not covered by $S_1$, and each point in $T$ can cover at most $3 + 3 = 6$ points in $P$. Therefore there are at least  
$$252 - (6 \times 25) = 102$$  
points in $P$ that must be covered by points in $S \setminus S_1 \setminus T$.

However,  
$$|S \setminus S_1 \setminus T| = 31 - 3 - 25 = 3,$$  
and each point in the cube covers exactly 22 points. Since  
$$22 \times 3 = 66 < 102,$$  
we have our contradiction.
