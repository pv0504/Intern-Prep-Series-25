## Solution

Please note that this question cannot be solved with any algorithm if terrorists are more than or equal to anti, because terrorists can plan to always lie.

Another solution taking only N-1 queries: We will try to find a chain of persons (i1,i2,i3....im) such that each ij is queried about i(j+1) and answer is correct. Note that if such chain contains an anti then last person in the chain would be anti. So query person 1 about 2. If answer is yes query person 2 about 3. Continue till answer is correct. Suppose at some point person i when queried about person j says wrong, in that case remove person i and j from the chain, and continue query process by querying predecessor of i about successor of j. Here note that when we remove person i and j from the chain at-least one of them must be faulty. Here for each person except the first one, we are querying once. Hence N-1 comparison in worst case. Think about the best case using this algorithm.
