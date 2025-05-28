## Solution: Infected Checkerboard 

### First some theory about a useful way of solving puzzles 
Puzzles often involve processes—systems that evolve in time randomly, deterministically, or under your control. Popular questions include: Can the system reach a certain state? Does it always reach a certain state? If so, how long does it take?
The key to such a puzzle may be to identify some parameter of the current state of the system that measures progress toward your goal.
We call such a parameter a potential.
For example, suppose you can show that the potential never increases, but starts below the potential of the desired end state. Then
you have proved that the end state is unreachable.


---

### Solution to the puzzle

At first it might seem that to infect the whole board, you need to start with a sick square in every row (and in every column). That would imply the conclusion, but it’s not true. For example, sick squares in alternating positions in the leftmost column and bottom row can infect the whole board.

What we really need is a potential function, and the one that works like a charm here is “perimeter.” 
The perimeter of the infected region is just the total length of its boundary. We may as well assign each grid edge length 1, so the perimeter could as well be defined as the number of edges that have a sick square on one side and either a well square or nothing on the other side.

Here is the key observation: When a square becomes infected (by two or more neighbors), the perimeter cannot increase! Indeed, it is easy to check that when just two neighbors administer the dose, the perimeter remains the same; if the well square had three or four sick neighbors, the perimeter actually goes down. If the whole board gets infected, the final perimeter is 4n; since the perimeter never increased, the initial perimeter must have been at least 4n. But to start with perimeter 4n there must have at least n sick squares.

---

Try solving this puzzle using the concept of potential:

Suppose that you are given an m × n array of real numbers and permitted, at any time, to flip the signs of all the numbers in any row or column. Can you always arrange matters so that all the row sums and column sums are non-negative?