n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Compute prefix sums (1-based indexing)
prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + arr[i]

# Process queries
for _ in range(q):
    a, b = map(int, input().split())
    print(prefix[b] - prefix[a - 1])
