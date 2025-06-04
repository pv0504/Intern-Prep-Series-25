from typing import List
def maxArea(height: List[int]) -> int:
    left, right, res = 0, len(height) - 1, 0
    while left < right:
        res = max(res, min(height[left], height[right]) * (right - left))
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return res
