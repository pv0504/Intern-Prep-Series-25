import sys
sys.setrecursionlimit(2 * 10**5 + 10)

n = int(input())
tree = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

def dfs(u, parent, dist):
    farthest = (dist, u)
    for v in tree[u]:
        if v != parent:
            farthest = max(farthest, dfs(v, u, dist + 1))
    return farthest

_, node = dfs(1, -1, 0)
diameter, _ = dfs(node, -1, 0)
print(diameter)
