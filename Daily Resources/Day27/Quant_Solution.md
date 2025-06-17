## ✅ Solution: Soldiers in a Field

Let’s look at the **pair of soldiers who are closest** to each other.
Because their distance is the smallest, each must be watching the other — since no one else is closer to either of them.

If any other soldier is also watching one of these two, then someone is being watched twice, which means someone else isn’t being watched at all — since there are an odd number of soldiers and everyone is supposed to watch exactly one other person.

So we can safely remove this closest pair, knowing that they’re watching each other and no one else is watching them. This doesn’t affect the structure for the remaining soldiers.

Repeat this process — each time removing a pair of mutually-watching soldiers.

Eventually, we’ll be left with one unpaired soldier, who isn’t being watched by anyone (because we remove in pairs), contradicting the assumption.
