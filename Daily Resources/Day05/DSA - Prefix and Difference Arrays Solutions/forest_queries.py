n, q = map(int, input().split())

# Read forest grid
forest = [input().strip() for _ in range(n)]

# Build prefix sum grid
prefix = [[0] * (n + 1) for _ in range(n + 1)]

for y in range(1, n + 1):
    for x in range(1, n + 1):
        is_tree = 1 if forest[y - 1][x - 1] == '*' else 0
        prefix[y][x] = prefix[y - 1][x]+ prefix[y][x - 1]- prefix[y - 1][x - 1]+ is_tree
        

# Process queries
for _ in range(q):
    y1, x1, y2, x2 = map(int, input().split())
    result = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1]
    
    print(result)
