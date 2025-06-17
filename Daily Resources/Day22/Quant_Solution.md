## ✅ Solution: Even-sum Billiards

If there were no ball numbered 9, then the sum would be even with probability exactly $\frac{1}{2}$ — since no matter what happens in your first 9 picks, the parity of the 10th ball determines the parity of the sum, and it's equally likely to be odd or even.

Now, put ball 9 back in.

No matter what order you choose the balls in, you can imagine your assistant revealing the numbers to you with all the 9’s first. Then the same logic applies: the parity of the **last non-9** number determines the parity of the entire sum. Since it ranges from 1 to 8 uniformly, the sum is still equally likely to be odd or even.

Oops, wait! There’s **one** scenario we haven’t considered:
What if you pick the 9-ball **every single time**?

That happens with probability $\left(\frac{1}{9}\right)^{10}$ — and in that case, the sum is $90$, which is even.

So overall, we slightly **increase** the probability of getting an even sum:

$$
\left(1 - \left(\frac{1}{9}\right)^{10}\right) \cdot \frac{1}{2} + \left(\frac{1}{9}\right)^{10}
= \frac{1}{2} + \frac{1}{2} \cdot \left(\frac{1}{9}\right)^{10}
$$

Which is approximately **0.50000000014** —
probably not enough of a bias to bet on!
