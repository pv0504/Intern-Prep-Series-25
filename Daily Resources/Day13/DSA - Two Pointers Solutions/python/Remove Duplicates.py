from typing import List
def removeDuplicates(nums: List[int]) -> int:
    if not nums: return 0
    i = 0
    for n in nums:
        if i == 0 or n != nums[i-1]:
            nums[i] = n
            i += 1
    return i
