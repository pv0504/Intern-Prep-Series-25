## Solution: Numbers on Foreheads

It is useful in many problems to introduce probability,
even though none is present in the statement. Here, if we assume that
the numbers painted on foreheads are chosen independently and uniformly at random, we see that no matter what he does, each prisoner
has probability 1/10 of guessing correctly.

Let the prisoners be numbered from 0 to 9. Since we want the
probability that some prisoner guesses correctly to be 1, we need the
10 events “Prisoner k guesses correctly” to be mutually exclusive: In
other words, no two can occur. Otherwise, the probability of at least
one success would be strictly less than 10(1/10) = 1.

To do this it would behoove us to separate the set of possible configurations into 10 equally likely scenarios, then have each prisoner
base his guess on a different scenario. This reasoning may already
have led you to the easiest solution: Let *s* be the sum of the numbers
on all the prisoners’ foreheads, modulo 10 (in other words, the rightmost digit of the sum). Now let Prisoner *k* guess that *s = k*, in other
words, guess that his own number is *k* minus the sum of the numbers
he sees, modulo 10.
This will ensure that Prisoner *s*, whoever that may be, will be correct (and all others wrong).

