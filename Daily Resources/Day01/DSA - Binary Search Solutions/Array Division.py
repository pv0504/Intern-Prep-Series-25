def is_valid(nums, k, max_sum):
    count = 1
    current = 0
    for num in nums:
        if current + num > max_sum:
            count += 1
            current = num
            if count > k:
                return False
        else:
            current += num
    return True

def find_min_largest_sum(nums, k):
    low = max(nums)
    high = sum(nums)
    result = high

    while low <= high:
        mid = (low + high) // 2
        if is_valid(nums, k, mid):
            result = mid
            high = mid - 1
        else:
            low = mid + 1
    return result

# Read input
n, k = map(int, input().split())
nums = list(map(int, input().split()))

# Output result
print(find_min_largest_sum(nums, k))
