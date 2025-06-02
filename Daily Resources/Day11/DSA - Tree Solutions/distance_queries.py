import sys
input = sys.stdin.read
sys.setrecursionlimit(1 << 25)

data = input().split()
n, q = int(data[0]), int(data[1])
edges = data[2:2 + 2 * (n - 1)]
queries = data[2 + 2 * (n - 1):]

LOG = 20
tree = [[] for _ in range(n + 1)]
up = [[-1]*LOG for _ in range(n + 1)]
depth = [0]*(n + 1)

for i in range(0, len(edges), 2):
    a, b = int(edges[i]), int(edges[i+1])
    tree[a].append(b)
    tree[b].append(a)

def dfs(u, p):
    up[u][0] = p
    for i in range(1, LOG):
        if up[u][i-1] != -1:
            up[u][i] = up[up[u][i-1]][i-1]
    for v in tree[u]:
        if v != p:
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

out = []
for i in range(0, len(queries), 2):
    a, b = int(queries[i]), int(queries[i+1])
    l = lca(a, b)
    out.append(str(depth[a] + depth[b] - 2 * depth[l]))

print('\n'.join(out))
