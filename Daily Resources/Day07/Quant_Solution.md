# Dynamic Card Game

Let $$v(r,b)$$ be the expected value of the game for the player, assuming optimal play, where:
- $$r$$: number of remaining red cards,
- $$b$$: number of remaining black cards.

## Recursive Formula

The value function $$v(r,b)$$ satisfies the following recurrence:

$$
v(r,b) =
\begin{cases}
0 & \text{if } r = 0, \\\\
r & \text{if } b = 0 \text{ and } r > 0, \\\\
\max(0, f(r,b)) & \text{if } r > 0 \text{ and } b > 0,
\end{cases}
$$

where

$$
f(r,b) = \frac{r}{r+b}(1 + v(r-1, b)) + \frac{b}{r+b}(-1 + v(r, b-1))
$$

The stopping rule is simple: Stop when $$v(r,b) = 0$$.

### Explanation
- If there are no red cards left ($$r = 0$$), the expected value is zero because no more positive points can be gained.
- If there are red cards but no black cards ($$b = 0$$), the player is guaranteed to win every round, gaining +1 per red card. So $$v(r,0) = r$$.
- If both red and black cards are left, the player can choose either to continue (gaining expected value $$f(r,b)$$) or stop (gaining 0). The player picks the maximum of the two options.

### Recursive Value Function Dynamics
- With probability $$\frac{r}{r+b}$$, a red card is revealed: score becomes $$+1 + v(r-1,b)$$.
- With probability $$\frac{b}{r+b}$$, a black card is revealed: score becomes $$-1 + v(r,b-1)$$.

## Table of Values

| $$v(r,b)$$ | $$b=0$$ | $$b=1$$ | $$b=2$$ | $$b=3$$ | $$b=4$$ |
|-----------|---------|---------|---------|---------|---------|
| $$r=0$$   | 0.0000  | 0.0000  | 0.0000  | 0.0000  | 0.0000  |
| $$r=1$$   | 1.0000  | 0.5000  | 0.0000  | 0.0000  | 0.0000  |
| $$r=2$$   | 2.0000  | 1.3333  | 0.6667  | 0.2000  | 0.0000  |
| $$r=3$$   | 3.0000  | 2.2500  | 1.5000  | 0.8500  | 0.3429  |
| $$r=4$$   | 4.0000  | 3.2000  | 2.4000  | 1.6571  | 1.0000  |

## Optimal Stopping Strategy

The player should stop when $$v(r,b) = 0$$. Based on the computed values, the optimal stopping strategy is:

- If $$3 \leq b \leq 4$$, play while $$r \geq b - 1$$.
- If $$1 \leq b \leq 2$$, play while $$r \geq b$$.
- If $$b = 0$$, play while $$r > 0$$.

This strategy ensures that the expected value from continuing the game remains non-negative and maximizes the player's expected score.
