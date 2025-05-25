from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findLeft():
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return left

        def findRight():
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] <= target:
                    left = mid + 1
                else:
                    right = mid - 1
            return right

        left_index = findLeft()
        right_index = findRight()

        if left_index <= right_index and left_index < len(nums) and nums[left_index] == target:
            return [left_index, right_index]
        else:
            return [-1, -1]
