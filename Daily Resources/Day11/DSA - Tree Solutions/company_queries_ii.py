import sys
input = sys.stdin.read
sys.setrecursionlimit(2 * 10**5 + 10)

data = input().split()
n, q = int(data[0]), int(data[1])
boss = [0] + [int(x) for x in data[2:n]]
queries = data[n:]

LOG = 20
up = [[-1] * LOG for _ in range(n + 1)]
depth = [0] * (n + 1)
tree = [[] for _ in range(n + 1)]

for i in range(2, n + 1):
    tree[boss[i - 1]].append(i)

def dfs(u, p):
    up[u][0] = p
    for i in range(1, LOG):
        if up[u][i-1] != -1:
            up[u][i] = up[up[u][i-1]][i-1]
    for v in tree[u]:
        depth[v] = depth[u] + 1
        dfs(v, u)

dfs(1, -1)

def lca(a, b):
    if depth[a] < depth[b]:
        a, b = b, a
    for i in range(LOG - 1, -1, -1):
        if depth[a] - (1 << i) >= depth[b]:
            a = up[a][i]
    if a == b:
        return a
    for i in range(LOG - 1, -1, -1):
        if up[a][i] != -1 and up[a][i] != up[b][i]:
            a = up[a][i]
            b = up[b][i]
    return up[a][0]

res = []
for i in range(0, len(queries), 2):
    a = int(queries[i])
    b = int(queries[i+1])
    res.append(str(lca(a, b)))

print('\n'.join(res))
