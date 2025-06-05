## Solution : Overflowing Buckets

It’s safe to assume your opponent will always empty the fullest two buckets. To force your opponent to pour out as little water as possible, it’s natural to begin by keeping all the buckets at the same level. How far will this get you? You’ll start by putting $1/12$ of a gallon in each bucket; your opponent will empty two buckets, reducing the total amount of water to $10/12$. You can then add a gallon total to bring each bucket up  
to  
$$(1 + 10/12)/12 = 11/72
$$  
Continuing in this manner, you make progress as long as the amount in each bucket is less than half a gallon (since then your opponent is pouring off less than you’re adding). You can get close to, but never quite reach, half a gallon per bucket by this method. Then what?  
Then you’re going to need to give up on keeping all the buckets level. Suppose you build up to $x$ gallons per bucket, then give up on the two buckets your opponent just emptied, and fill the rest evenly. Then you can get $x + 1/10$ gallons in those; she empties two of them and you build up to $x + 1/10 + 1/8$ in the remaining eight, and so on.  
You end with  
$$x+1/10+1/8+1/6+1/4+1/2 = x+1.141666
$$  
in the last two buckets, not good enough to cause overflow, since $x < 1/2$.  
But wait—you don’t need two buckets overflowing, only one. So, you start by building up only 11 buckets, with the idea of later reducing to 9, 7, 5, 3, and finally, 1 bucket. That will get you up to  
$$x + 1/9 + 1/7 + 1/5 + 1/3 + 1 \sim x + 1.7873015873
$$  
That’s more like it! So it’s enough to get $x \geq 0.2127$.
