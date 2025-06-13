## Solution: Second Ace

There are
${{52}\choose{5}} - {{48}\choose{5}}$
poker hands with at least one ace, and
${{52}\choose{5}} - {{48}\choose{5}} - {{4}\choose{1}}{{48}\choose{4}}$
with at least two aces.
Dividing the latter by the former gives our first answer:
**0.12218492854**.

Now, for the second part:
There are ${{51}\choose{4}}$ hands containing the Ace of Spades, and
${{4}\choose{1}}{{48}\choose{3}}$ containing another ace as well, giving our second answer:
**0.22136854741**, quite a lot larger than the first.

Of course, there’s nothing special about the Ace of Spades; speci­fying the ace held changes the conditional probabilities.

Here’s a simpler analogy:
Suppose a third of the families in town have two children, a third have one, and the remaining third none. Then the probability that a family has a second child, given that it has at least one, is ½.
But the probability that a family has a second child given that it has a girl is ⅗, because only half the families with one child have a girl, but ¾ of those with two children have a girl.
