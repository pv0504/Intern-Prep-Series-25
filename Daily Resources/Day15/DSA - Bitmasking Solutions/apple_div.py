n = int(input())
weights = list(map(int, input().split()))
total = sum(weights)
min_diff = float('inf')

for mask in range(1 << n):
    group_sum = 0
    for i in range(n):
        if mask & (1 << i):
            group_sum += weights[i]
    other_sum = total - group_sum
    min_diff = min(min_diff, abs(group_sum - other_sum))

print(min_diff)
