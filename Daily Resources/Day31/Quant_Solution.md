# Solution to the Expected Length of the Coin Game

## Solution 1

Let us denote $K = m + n$. There are two ways the game may end: the winner is either you or me. Conditioned on me being the winner, let $L(x),\ 0 \leq x \leq K$, be the expected length of the game if I have $x$ coins. There is an obvious recurrence relation:

$$
L(x) = \frac{1}{2}L(x-1) + \frac{1}{2}L(x+1) + 1,
$$

as I can win or lose a coin with the same probability of $\frac{1}{2}$. One is added to the account for the present toss.

Thus, we have an inhomogeneous difference equation of order two:

$$
L(x+1) - 2L(x) + L(x-1) + 2 = 0.
$$

The characteristic polynomial of the homogeneous equation has a double root 1, such that the general solution of the inhomogeneous equation is a quadratic polynomial, say:

$$
L(x) = u + vx + wx^2.
$$

Substituting into the recurrence yields:

$$
2w = -2 \Rightarrow w = -1.
$$

For the boundary conditions, we have:  
- $L(0) = 0 \Rightarrow u = 0$  
- $L(K) = 0 \Rightarrow v = K$

Thus, the solution is:

$$
L(x) = x(K - x).
$$

If I start with $n$ coins, then:

$$
L(n) = n(K - n) = mn.
$$

Naturally, the expectation is symmetric in $n$ and $m$.

---

## Solution 2  

Let $E(n, m)$ be the expected length of the game in the case I start with $n$ and you start with $m$ coins. On a toss, we move to either $E(n-1, m+1)$ or $E(n+1, m-1)$, each with probability $\frac{1}{2}$, leading to the recurrence relation:

$$
E(n, m) = 1 + \frac{1}{2}E(n-1, m+1) + \frac{1}{2}E(n+1, m-1),
$$

where the 1 indicates the first toss. This assumes $n, m > 0$.  
Boundary conditions:

- $E(0, m) = 0$
- $E(n, 0) = 0$

If we view $E(n, m)$ as a function of one variable, say $n$, along the line $m + n = \text{constant}$, then the formula implies the second difference is constant ($-2$). So, $E(n, m)$ is a quadratic function.

Vanishing at the endpoints forces this to be $cmn$, and direct evaluation shows that $c = 1$, implying:

$$
E(n, m) = mn.
$$

---

## Solution 3  

Let $E(k)$ be the expected value of the length of the game if I am in possession of $k$ coins. Then:

$$
E(k) = \frac{1}{2}(E(k+1) + E(k-1)).
$$

This simplifies to a second difference equation:

$$
(E(k+1) - E(k)) - (E(k) - E(k-1)) = -2.
$$

In terms of the difference operator $\Delta$, this becomes:

$$
\Delta^2 E = -2,
$$

which implies $E$ is a quadratic function:

$$
E(k) = -k(k - 1) + ak + b.
$$

Boundary conditions:  
- $E(0) = 0 \Rightarrow b = 0$  
- $E(m + n) = 0 \Rightarrow a = m + n - 1$

So,

$$
E(k) = -k(k - 1) + k(m + n - 1).
$$

At the beginning of the game:

$$
E(m) = -m(m - 1) + m(m + n - 1) = mn.
$$
