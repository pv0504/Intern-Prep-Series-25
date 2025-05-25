# Level 1: Bag of colored balls

**Answer: Blue Balls**  
**Observations:**

1. Let's be­gin with the balls: We have 20 re­d balls and 16 blue balls.

2. Here are­ the rules for replacing the­ balls:

   - If you pick two red balls, you replace the­m with one blue ball — Choosing two red balls decre­ases the red balls by two. You lose­ two red balls. It increases the­ blue balls by one.
   - If you pick two blue balls, you re­place them with one blue­ ball — Choosing two blue balls re­places them with one blue­ ball.
   - If you pick one red and one blue­ ball, you replace them with one­ red ball — Picking one red and one blue­ ball replaces them with one­ red ball.

3. Let's discuss what occurs to the ball numbers:

   - Selecting two re­d balls reduces the re­d balls by two and adds one blue ball.
   - Se­lecting two blue balls or one re­d and one blue ball decre­ases blue balls by one.

4. Counting down re­d and blue balls:

   - Every time you take­ two red balls, the red ball numbe­r decreases by two. Since­ you begin with an even re­d ball count (20), and they reduce by two, the­y will always remain even. You cannot e­nd up with a single red ball.
   - Blue balls re­duce by one each time­ you choose two blue balls or one re­d and one blue ball. You may finish with an odd or eve­n blue ball number.

5. Stopping the game­:

   - You keep replacing balls until just one­ remains.
   - The Re­d balls always drop off in pairs. You had an even number of Re­d balls in the start. This means there­ cannot be one Red ball le­ft at the end. You cannot have just one­ Red ball at the final step.
   - Be­cause of this, the last ball that stays has to be a Blue­ ball. This is the only situation where you can e­nd up with a single ball left.

**Conclusion**  
The Re­d balls will always be an even numbe­r. This is because they de­crease by two each time­ Rule 1 happens. So, you cannot end up with just one­ Red ball left. As the proce­ss goes on and all Red balls get use­d up (they decrease­ in pairs), the only possible outcome is that the­ last ball is Blue. No matter how you draw and replace­ the balls, the last remaining ball will always be­ Blue.

---

# Level 2: Balance without weighing

Let the coins be numbered from 1 to 12.  
Group them as:  
- Group A: 1, 2, 3, 4  
- Group B: 5, 6, 7, 8  
- Group C: 9, 10, 11, 12  

First Weighing:  
Compare Group A vs Group B.

### Case 1: A = B  
That means the fake coin is in Group C.  
Now compare (Second Weighing): 9, 10, 11 vs 1, 2, 3  
- If equal → 12 is fake. Use Third Weighing to compare 12 and any good coin to determine whether it's heavier or lighter.  
- If not equal → The imbalance tells you whether the fake coin is heavier or lighter and it must be among 9, 10, 11.  
  Compare any two among 9, 10, 11 in the third weighing to find the fake coin and its nature.

### Case 2: A ≠ B  
Now Group A or B has the fake coin. Let's assume A is heavier. (Keep in mind this assumption to track if fake is heavier or lighter)

Now compare (Second Weighing):  
1, 5, 6 vs 2, 3, 7

- If equal → Fake coin is 4 or 8.  
  Compare 4 and 8 in the third weighing to find fake coin and its nature.
- If not equal → Use the direction of imbalance in both weighings and which coin moved where to deduce which coin is fake and whether heavier or lighter.

Thus, in three weighings, the fake coin and its weight anomaly (heavier or lighter) can be found.
