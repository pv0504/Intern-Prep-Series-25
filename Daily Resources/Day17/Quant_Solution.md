# ✅ Solution – Dice Question

We can solve this problem using conditional probability arguments. Let $P(A)$ be the probability that Alex wins. 

We can condition $P(A)$ on the first throw's sum $F$, which has three possible outcomes:
- $F = 12$ (Alex wins immediately)
- $F = 7$ (first seven rolled)  
- $F \neq 7, 12$ (neither 7 nor 12 rolled)

Using simple counting, we can calculate:
- $P(F = 12) = \frac{1}{36}$
- $P(F = 7) = \frac{6}{36}$  
- $P(F \neq 7, 12) = \frac{29}{36}$

The conditional probabilities are:
- $P(A | F = 12) = 1$ (Alex wins immediately)
- $P(A | F \neq 7, 12) = P(A)$ (game continues as if starting over)

To calculate $P(A | F = 7)$, we condition on the second throw's total $E$:
- $E = 12$ (Alex wins)
- $E = 7$ (Bob wins with consecutive sevens)
- $E \neq 7, 12$ (game continues)

Using the law of total probability:

$P(A) = P(A | F = 7) \cdot P(F = 7) + P(A | F = 12) \cdot P(F = 12) + P(A | F \neq 7, 12) \cdot P(F \neq 7, 12)$

$P(A | F = 7) = P(A | F = 7, E = 12) \cdot P(E = 12 | F = 7) + P(A | F = 7, E = 7) \cdot P(E = 7 | F = 7) + P(A | F = 7, E \neq 7, 12) \cdot P(E \neq 7, 12 | F = 7)$

Since throws are independent, we have $P(E = k | F = 7) = P(E = k)$ for any value $k$.

Solving this system of equations gives us:
$P(A) = \frac{7}{13}$

---

**Alternative Markov Chain Approach:**

We can model this as a Markov chain with states:
- $S$: Starting state
- $7$: One seven has been rolled (but no consecutive sevens or twelve yet)
- $7-7$: Two consecutive sevens (Bob wins)
- $12$: A twelve has been rolled (Alex wins)

States $7-7$ and $12$ are absorbing states. We compute the transition probabilities and find the probability of reaching state $12$ from state $S$, which again gives $P(A) = \frac{7}{13}$.