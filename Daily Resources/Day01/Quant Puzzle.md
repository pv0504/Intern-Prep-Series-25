# 🧠 Quant Puzzle – Day 1

## 📌 Topic: Magical Fruit Collision

### 🤔 What’s the Puzzle?

We have:

- 🍎 13 Apples  
- 🍌 15 Bananas  
- 🍒 17 Cherries  

All placed inside a magic hat. Whenever a collision occurs between two different fruits, both disappear and are replaced by two of the third type.

📌 Only these collisions are allowed:
- Apple + Banana → 2 Cherries  
- Banana + Cherry → 2 Apples  
- Cherry + Apple → 2 Bananas

> 🧙‍♂ No other transformation is holy!

---

### ❓ Main Question

Can a sequence of such magical collisions lead to a final state where all 45 fruits are of just one type?

---

### ✅ Your Turn: Pick an Answer

Choose one:
- [ ] Yes, it's possible.
- [ ] ❌ No, it's impossible.

---

### 📂 Reveal Solution

Click below to toggle the explanation if you're stuck or want to check your answer.

<details>
<summary>📜 Click to Show Solution</summary>

#### 🔄 Invariant Method:

Let’s define a function:


f(A, B, C) = A + 2B + 3C mod 3


✅ This value stays constant through all valid collisions.

Initial value:

f(13, 15, 17) = 13 + 2×15 + 3×17 = 94 ≡ 1 mod 3


Now check each final state:
- f(45, 0, 0) = 45 ≡ 0 mod 3 ❌
- f(0, 45, 0) = 2×45 = 90 ≡ 0 mod 3 ❌
- f(0, 0, 45) = 3×45 = 135 ≡ 0 mod 3 ❌

None match the initial invariant (1 mod 3) ⇒ contradiction.

So even though transformations seem to reduce fruit variety, we can’t reach any all-one-fruit state.

---

#### 🧮 System of Equations Method:

Let:  
- A = # of times Apples are increased by 2  
- B = # of times Bananas are increased by 2  
- C = # of times Cherries are increased by 2

From transformation rules:

- (AB)Apple + Banana → 2 Cherries  
- (BC)Banana + Cherry → 2 Apples  
- (CA)Cherry + Apple → 2 Bananas  

We derive:


Final Apples = 13 - (AB + CA) + 2 × BC  
Final Bananas = 15 - (BC + AB) + 2 × CA  
Final Cherries = 17 - (CA + BC) + 2 × AB


Trying to set two of these to zero and one to 45 leads to non-integer solution in the equation system.

So again, impossible.

---

### 🛑 Final Answer: No, it's impossible.

</details>

---

### 🔑 Key Takeaways

- Invariants like f(A,B,C) mod 3 help prove impossibility in transformation problems.
- Using algebraic constraints ensures no overlooked cases.
- These puzzles are great practice for reasoning, modular arithmetic, and logic — crucial in quant interviews.

## 🧩 Related Problems

- [Three Piles Game](https://mindyourdecisions.com/blog/2014/02/10/monday-puzzle-three-piles-of-coins/)
- [Chocolate and Wrappers](https://www.geeksforgeeks.org/puzzle-22-maximum-chocolates/)
- [Light Switch Puzzle](https://brainstellar.com/puzzles/4/)
- [Burning Rope Puzzle](https://brainstellar.com/puzzles/10/)
- [Two Water Jugs Problem](https://brainstellar.com/puzzles/17/)
