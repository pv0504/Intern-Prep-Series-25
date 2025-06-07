## Solution : Optimal Coins

This puzzle resists the most obvious approaches. It’s easy to check that Alix could do quite badly by always choosing the most valuable coin, or the coin that exposes the less valuable coin to Bert,
or any combination of these. Basically, if she only looks a move or two ahead, she’s in trouble.
In fact, for Alix to play optimally, she needs to analyze all the possible situations that may later arise. This can be done by a technique called “dynamic programming.”
But we were not asked to provide an optimal strategy for Alix, just a strategy that guarantees her at least half the money. Experimenting with 4 or 6 coins instead of 50 might lead you to the following key observation. Suppose the coins alternate quarter, penny, quarter, penny, and so forth, ending (since 50 is even) in a penny. Then Alix can get all the quarters! In fact, no matter what the coins are, if we number the coins from 1 to 50 left to right, Alix can take all the odd-numbered ones—or all the even-numbered ones.
But wait a minute—one of those two groups of coins must contain at least half the money! 