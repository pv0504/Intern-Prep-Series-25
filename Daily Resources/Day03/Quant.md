# 🧠 Quant Puzzle – Day 3

## 📌 Topic: Blindfold Coin Separation

### 🤔 What’s the Puzzle?

Imagine yourself standing in a room with a blindfold on. You are informed that there are *1000 coins* scattered on the floor. Out of those coins, *980 have tails* facing upwards while the remaining *20 have heads* facing upwards.

You are given a task to *separate the coins into two piles. Can you ensure that **both piles have an equal number of heads facing upwards? However, you are **not allowed to touch or feel the coins to determine their sides, but you **can flip over as many coins as you want*.

---

### 📂 Reveal Solution

<details>
<summary>📜 Click to Show Solution</summary>

We are given **1000 coins**, out of which **980 have tails** facing upwards and **20 have heads** facing upwards. We need to separate the coins into **two piles** such that **both piles have an equal number of heads** facing upwards. We cannot touch or feel the coins to determine their sides, but we **can flip over as many coins as we want**.

Let’s assume that we separate the coins into two piles with **n coins** in one pile and **1000 − n coins** in the other. Let **m** be the number of coins in the first pile with heads up. Then there must be **20 − m** coins in the second pile with heads up. 

We also know that there are **n − m** coins in the first pile with tails up.

Now, if we **flip all the coins in the first pile**, all heads become tails and all tails become heads. As a result, the first pile will now have:

- **n − m heads** (original tails flipped to heads), and  
- **m tails** (original heads flipped to tails).

To ensure that **both piles have the same number of heads after the flip**, we require:

$$
\text{Number of heads in flipped first pile} = n - m
$$

And the number of heads in the second pile remains:

$$
\text{Number of heads in second pile} = 20 - m
$$

To make the number of heads equal in both piles, we equate:

$$
n - m = 20 - m
$$

Simplifying gives:

$$
n = 20
$$

---

So the trick is:

- Take **any 20 coins at random**, put them in the first pile.
- Put the remaining **980 coins** in the second pile.
- **Flip all 20 coins** in the first pile.

Now, both piles are guaranteed to have **the same number of heads**.

No matter what the original configuration was, the number of heads in both piles will now be *equal*.

</details>

---

### 🔑 Key Takeaway

This puzzle is a great example of solving a problem *without knowing specific details*, relying purely on logic and symmetry.

---

## 🧩 Bonus Puzzles

### Level 1: Flipping Identity

You have 10 coins in a line, each showing either heads or tails. You're allowed to flip exactly *3 consecutive coins* in one move. Is it possible to reach a state where *all coins are heads*, regardless of the starting configuration?

---

### Level 2: Bag of Colored Balls

A bag contains **20 blue balls** and **14 red balls**. Each time, you randomly take **two balls out** of the bag. (Assume each ball in the bag has an equal probability of being chosen.)

- If **both balls are of the same color**, you **add a blue ball** to the bag.
- If the balls are of **different colors**, you **add a red ball** to the bag.

You do **not** put the two balls you took out back into the bag.

You have an **unlimited supply** of red and blue balls to add as needed.

If you continue this process until **only one ball remains**, what will be the **color** of the **last ball** left in the bag?
---

### Level 3: Balance Without Weighing

You have 12 coins. One of them has a different weight (heavier or lighter), but you don’t know which. You’re allowed *3 weighings* using a balance scale. Can you *identify the odd coin and whether it is heavier or lighter*?

---
