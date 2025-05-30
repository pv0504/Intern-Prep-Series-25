class Solution:
    def characterReplacement(self, s, k):
        count = [0] * 26
        left = 0
        max_freq = 0
        result = 0

        for right in range(len(s)):
            idx = ord(s[right]) - ord('A')
            count[idx] += 1
            max_freq = max(max_freq, count[idx])

            while (right - left + 1) - max_freq > k:
                count[ord(s[left]) - ord('A')] -= 1
                left += 1

            result = max(result, right - left + 1)

        return result
