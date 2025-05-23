class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        import math

        def can_finish(speed):
            hours = 0
            for pile in piles:
                hours += math.ceil(pile / speed)
            return hours <= h

        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1
        return left
