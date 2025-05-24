# 🧠 Quant Puzzle – Day 2

## 📌 Topic: Bugs on a Pyramid

### 🤔 What’s the Puzzle?

Four bugs start at the four corners of a triangular pyramid (tetrahedron). Each bug decides to take a walk along the surface of the pyramid.  The bugs are allowed to move at different speeds.

At the end of their walk:

* Two bugs return to their original corners.
* The other two bugs end up having swapped places.

**Question:**
Must there have been a moment during their movement when all four bugs were on the same plane?

**EUREKA**
* The main point i learned was whenever the questions related to coplanar or meeting at some point was given, then you need to do using this type of method like IVT which helps in changing direction, one such example is by taking volume of tetrahedron.
---

### 💡 Hints

<details>
<summary>Hint 1</summary>

Try to think about how the orientation of three bugs appear from the fourth bug's perspective. Can the fourth bug notice any change in the initial and the final states?


</details>

<details>
<summary>Hint 2</summary>
Try to apply a topological idea: if a system transitions from one configuration to a "reversed" configuration, what does the Intermediate Value Theorem suggest?
</details>

---

### 📂 Reveal Solution

<details>
<summary>📜 Click to Show Solution</summary>

Let the bugs be A, B, C, and D. Initially when D looks
down on the ABC plane she sees the ABC triangle in a certain orientation (say, clockwise).

By the end, D has swapped with one of A, B, or C — and now sees triangle ABC with the **opposite** orientation.

Since the bugs move continuously, the orientation must change continuously. So, there must be a moment when all four bugs are coplanar—either because D is on the plane of ABC, or because A, B, and C are collinear, which also makes them coplanar with D.

Therefore, **there was a moment when all four bugs lay on the same plane**.

</details>

---

## 🔑 Key Takeaway

Intermediate Value Theorem is a great tool to tackle problems involving motion, continuous change, or transitions.

---

## 🧩 Bonus Puzzles

### Level 1: Antipodal Points

Assume temperature and pressure are continuous functions over the Earth's surface.

**(a)** Must there be two **antipodal** (diametrically opposite) points on Earth with the same temperature?

**(b)** Must there be two antipodal points with the same **temperature and pressure**?

---

### Level 2: Skipping a number

At the start of a season, Lionel Messi had a career penalty conversion rate **below 80%**, and by the end of the season, his conversion rate was **above 80%**.

**Does this mean there must have been a moment during the season when Messi’s penalty conversion rate was exactly 80%?**

---

👉 Stay tuned, solutions to the bonus puzzles will be released tomorrow!

