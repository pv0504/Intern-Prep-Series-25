# 🧠 Quant Puzzle – Day 17

## 📌 Topic: Coin Triplets

### 🤔 What's the Puzzle?

You're playing a coin-tossing game where you flip a fair coin repeatedly until one of the following patterns appears:

- `HHH` — three heads in a row
- `THH` — a tail followed by two heads

The game stops when the **first** of these two patterns appears.

**What is the probability that `HHH` appears before `THH`?**

---

### 💡 Hint

<details>
<summary>Hint</summary>

Think of modeling the problem using a **Markov chain** with states based on the latest outcomes (`S`, `H`, `HH`, `T`, `TH`, etc). Track transitions until one of the absorbing states (`HHH` or `THH`) is reached.

</details>

---


---
