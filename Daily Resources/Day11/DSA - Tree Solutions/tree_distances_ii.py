import sys
sys.setrecursionlimit(2 * 10**5 + 10)

n = int(input())
tree = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

subsize = [1] * (n + 1)
res = [0] * (n + 1)

def dfs1(u, parent):
    for v in tree[u]:
        if v != parent:
            dfs1(v, u)
            subsize[u] += subsize[v]
            res[u] += res[v] + subsize[v]

def dfs2(u, parent):
    for v in tree[u]:
        if v != parent:
            res[v] = res[u] - subsize[v] + (n - subsize[v])
            dfs2(v, u)

dfs1(1, 0)
dfs2(1, 0)
print(' '.join(map(str, res[1:])))
