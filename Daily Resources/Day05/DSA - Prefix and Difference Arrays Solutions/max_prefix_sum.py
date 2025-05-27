class Solution:
    def maxPrefixes(self, arr, leftIndex, rightIndex):
        result = []
        for l, r in zip(leftIndex, rightIndex):
            current_sum = arr[l]
            max_prefix = current_sum
            for i in range(l + 1, r + 1):
                current_sum += arr[i]
                max_prefix = max(max_prefix, current_sum)
            result.append(max_prefix)
        return result
