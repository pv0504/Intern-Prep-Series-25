import sys
sys.setrecursionlimit(2 * 10**5 + 10)

n = int(input())
bosses = list(map(int, input().split()))
tree = [[] for _ in range(n + 1)]

for i, b in enumerate(bosses, start=2):
    tree[b].append(i)

res = [0] * (n + 1)

def dfs(u):
    for v in tree[u]:
        res[u] += 1 + dfs(v)
    return res[u]

dfs(1)
print(' '.join(map(str, res[1:])))
