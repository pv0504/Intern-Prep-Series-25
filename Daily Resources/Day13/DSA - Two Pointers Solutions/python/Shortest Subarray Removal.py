from typing import List
def findLengthOfShortestSubarray(arr: List[int]) -> int:
    n = len(arr)
    left, right = 0, n - 1
    while left + 1 < n and arr[left] <= arr[left + 1]:
        left += 1
    if left == n - 1:
        return 0
    while right > left and arr[right - 1] <= arr[right]:
        right -= 1
    res = min(n - left - 1, right)
    i, j = 0, right
    while i <= left and j < n:
        if arr[i] <= arr[j]:
            res = min(res, j - i - 1)
            i += 1
        else:
            j += 1
    return res
