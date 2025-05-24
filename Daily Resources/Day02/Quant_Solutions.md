### Level 1: Antipodal Points

Assume temperature and pressure are continuous functions over the Earth's surface.

---

#### (a) Must there be two antipodal (diametrically opposite) points on Earth with the same temperature?

**Yes.** This follows from the **Intermediate Value Theorem (IVT).**

Consider any great circle on Earth (e.g., the equator). For any point $p$ on this circle, let $p^*$ denote its **antipodal point** (diametrically opposite point on the circle).

Now define a function:

$$
f(p) = T(p) - T(p^*)
$$

where $T(p)$ is the temperature at point $p$. Since temperature is a continuous function on the Earth’s surface, $f(p)$ is continuous on the circle.

Note:

$$f(p^\*) = T(p^\*) - T(p) = -f(p)$$

This means: if $f(p) > 0$, then $f(p^*) < 0$, and vice versa.
By the **Intermediate Value Theorem**, a continuous function that changes sign must be zero somewhere.

Hence, there must be some point $p$ such that:

$$
f(p) = T(p) - T(p^*) = 0
$$

i.e., **two antipodal points with the same temperature**.

---

#### (b) Must there be two antipodal points with the same temperature **and** pressure?

**Yes.** This is a direct consequence of the **Borsuk-Ulam Theorem**.

The theorem states:

> For any continuous function $f: S^n \to \mathbb{R}^n$, there exists a point $x$ such that $f(x) = f(-x)$.

Here, define a function on the Earth's surface (a 2-sphere $S^2$):

$$
f(p) = (\text{temperature at } p, \text{pressure at } p) \in \mathbb{R}^2
$$

Since both temperature and pressure are continuous, $f$ is continuous.
By the Borsuk-Ulam Theorem, there exists a point $p$ such that:

$$
f(p) = f(-p)
$$

That is, **temperature and pressure are equal at two antipodal points**.

👉 A very visual and intuitive proof of this theorem can be found in this [3Blue1Brown video](https://youtu.be/yuVqxCSsE7c?si=z_0O5Tat2FwqYUcz&t=188).

---

### Level 2 : Skipping a number

At the start of a season, Messi's career penalty conversion rate was **below 80%**, and by the end of the season, it was **above 80%**.

**Question:**
Must there have been a point during the season when his career conversion rate was **exactly 80%**?


---

Let $H(t)$ be the number of penalties Messi had scored up to some time $t$, and $M(t)$ the number he had missed by that time. Observe that if there is a moment $t$ when his conversion rate is exactly 80% then:

$$
H(t) = 4 \cdot M(t)
$$

<!-- At the start of the season, his rate is **below** 80%, so $H(t) < 4 \cdot M(t)$.
At the end, it’s **above** 80%, so $H(t) > 4 \cdot M(t)$. -->

Let $t_0$ be the first moment when the rate reaches or passes 80%. This moment must have happened after a successful penalty, so at time $t_0$, $H(t)$ increased by 1, while $M(t)$ stayed the same.

But $H(t)$ can’t jump from **less than** $4 \cdot M(t)$ to **more than** $4 \cdot M(t)$ without passing through **equal to** $4 \cdot M(t)$. Since both $H(t)$ and $M(t)$ are integers, at some point:

$$
H(t) = 4 \cdot M(t)
$$

So, Messi **must** have had a moment when his conversion rate was **exactly 80%**.

---

