## ✅ Solution: Leading all the way


Of course, what we’d really like to do is solve this problem in general — when Alice has won with $a$ votes to Bob’s $b$, where $a$ and $b$ are arbitrary positive integers with $a > b$.

The answer is given by what is often known as **Bertrand’s Ballot Theorem**.

### Theorem

Let $a > b > 0$ and let $x = (x_1, x_2, \ldots, x_{a+b})$ be a uniformly random string of 1’s and −1’s, containing $a$ 1’s and $b$ −1’s. For each $k$ between $1$ and $a + b$, let $s_k$ be the sum of the first $k$ elements of $x$, that is,

$$
s_k = \sum_{i=1}^{k} x_i
$$

Then the probability that $s_1, s_2, \ldots, s_{a+b}$ are all positive is

$$
\frac{a - b}{a + b}
$$

Let’s first check that this statement tells us what we want to know.

The string $x$ codes the ballot-counting process; each $1$ represents a vote for Alice, each $-1$ a vote for Bob. The sum $s_k$ tells us by how much Alice leads after the $k$ th vote has been counted; for example, if $s_9 = -3$ we conclude that Alice was actually behind by three votes after the ninth vote was counted.

If we apply the theorem to the puzzle above, we get the answer:

$$
\frac{105 - 95}{105 + 95} = \frac{10}{200} = \frac{1}{20} = 5\%
$$

So how can we prove the theorem?

There’s a famous and clever proof that uses reflection of random walk (do look it up online), but doesn’t really explain why the probability turns out to be the vote difference divided by the total vote. Instead, consider the following argument.

---

One way to choose the random order in which the ballots are counted is to first place the ballots randomly in a circle, then to choose a random ballot in the circle and start counting (say, clockwise) from there. Since there are $a + b$ ballots, there are $a + b$ places to start, and the claim is that no matter what the circular order is, exactly $a - b$ of those starting points are "good" — in that they result in Alice leading all the way.

To see this, we observe that any occurrence of $1, -1$ (i.e., a vote for Alice followed immediately by a vote for Bob in clockwise order) can be deleted without changing the number of good starting positions.

**Why?**  
- First, you can’t start with that $1$ or $-1$, since if you start with the $1$ the candidates are tied after the second vote, and if you start with the $-1$, Alice actually falls behind.  
- Secondly, the $1, -1$ pair has no influence on the eligibility of any other starting point, since all it does is raise the sum (Alice’s lead) by one and then lower it again.

So we can keep deleting $1, -1$ pairs until all that’s left is $a - b$ 1’s, each of which is obviously a good starting point.

We conclude that all along there were $a - b$ good starting points, and we are done!
