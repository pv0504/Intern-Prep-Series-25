# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n
        while left < right:
            mid = left + (right - left) // 2
            if isBadVersion(mid):
                right = mid  # The first bad version is at mid or before
            else:
                left = mid + 1  # The first bad version must be after mid
        return left  # left == right at this point, and it's the first bad version
