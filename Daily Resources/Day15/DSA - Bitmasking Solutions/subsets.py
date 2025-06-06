class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        result = []

        for mask in range(1 << n):  # Loop from 0 to 2^n - 1
            subset = []
            for i in range(n):
                if mask & (1 << i):  # If the i-th bit is set
                    subset.append(nums[i])
            result.append(subset)

        return result
