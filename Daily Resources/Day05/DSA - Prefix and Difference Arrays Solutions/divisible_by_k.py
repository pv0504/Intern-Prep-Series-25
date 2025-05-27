from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        count[0] = 1  # one empty prefix with mod 0

        prefix_sum = 0
        result = 0

        for num in nums:
            prefix_sum += num
            mod = prefix_sum % k
            if mod < 0:
                mod += k  # ensure non-negative remainder

            result += count[mod]
            count[mod] += 1

        return result
