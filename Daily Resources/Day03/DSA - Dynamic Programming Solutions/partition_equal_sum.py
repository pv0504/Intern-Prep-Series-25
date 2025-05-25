class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        s = sum(nums)
        if s % 2:
            return False
        target = s // 2
        dp = [True] + [False] * target
        for x in nums:
            for t in range(target, x - 1, -1):
                dp[t] = dp[t] or dp[t - x]
        return dp[target]
