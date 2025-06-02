import sys
input = sys.stdin.read
sys.setrecursionlimit(2 * 10**5 + 10)

data = input().split()
n, q = int(data[0]), int(data[1])
boss = [0] + [int(x) for x in data[2:n]]  # boss[i] for i = 2 to n
queries = data[n:]

LOG = 20
up = [[-1] * LOG for _ in range(n + 1)]

for i in range(2, n + 1):
    up[i][0] = boss[i - 1]
up[1][0] = -1  # general director

for j in range(1, LOG):
    for i in range(1, n + 1):
        if up[i][j - 1] != -1:
            up[i][j] = up[up[i][j - 1]][j - 1]

res = []
for i in range(0, len(queries), 2):
    x = int(queries[i])
    k = int(queries[i + 1])
    for j in range(LOG):
        if k & (1 << j):
            x = up[x][j]
            if x == -1:
                break
    res.append(str(x if x != -1 else -1))

print('\n'.join(res))
