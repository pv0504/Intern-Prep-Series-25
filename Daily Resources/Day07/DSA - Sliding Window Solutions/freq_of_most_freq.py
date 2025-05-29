class Solution:
    def maxFrequency(self, nums, k):
        nums.sort()
        left = 0
        total = 0
        max_freq = 0
        
        for right in range(len(nums)):
            total += nums[right]
            # Check if the total operations to make all elements in window equal to nums[right] exceeds k
            while (right - left + 1) * nums[right] - total > k:
                total -= nums[left]
                left += 1
            max_freq = max(max_freq, right - left + 1)
        
        return max_freq
