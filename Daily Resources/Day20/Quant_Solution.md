## Solution

First let's find the expected number of coin tosses to get either 
HHH or 
THH. To solve this, we construct a Markov chain with four states: 
S, 
H, 
HH, and 
HHH. The transition probabilities are determined based on the outcomes of the coin tosses (for eg - from 
HH there is 
0.5 probability to go to 
HHH and 
0.5 to go to 
S).

Using the standard equations for the expected time to absorption, we find that the expected number of tosses to get 
HHH is 
14, and the expected number of tosses to get 
THH is 
8.

Now for the main problem, we consider a game where both players can choose their own triplets. We construct a Markov chain with states representing ordered subsequences of either 
HHH or 
THH. The states would be 
{S, H, T, HH, TH, HHH, THH} and transition probabilities can be easily constructed too. We want to find the probability of reaching the absorbing state 
HHH from the starting state 
S. Applying the equations for absorption probability, we find that the probability of ending up with the 
HHH pattern is 
1⁄8.

However there was an easier way to compute the result as well, we note that once a tail occurs, we will always get 
THH before 
HHH. Therefore, if we don't start the coin flipping sequence with 
HHH, we will always have 
THH before 
HHH. Hence the only way to get 
HHH is in the first 
3 throws, and this happens with 
1⁄8 probability.
