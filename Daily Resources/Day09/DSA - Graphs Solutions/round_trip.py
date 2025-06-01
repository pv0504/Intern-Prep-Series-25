import sys
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
vis = [False] * n
par = [-1] * n

for _ in range(m):
    x, y = map(int, input().split())
    adj[x-1].append(y-1)
    adj[y-1].append(x-1)

def dfs(a):
    vis[a] = True
    for c in adj[a]:
        if par[a] == c:
            continue
        if vis[c] and par[a] != c:
            par[c] = a
            return c
        else:
            par[c] = a
            x = dfs(c)
            if x != -1:
                return x
    return -1

for i in range(n):
    if not vis[i]:
        x = dfs(i)
        if x != -1:
            y = []
            z = x
            y.append(x)
            x = par[x]
            while z != x:
                y.append(x)
                x = par[x]
            y.append(x)
            print(len(y))
            print(' '.join(str(v + 1) for v in y))
            sys.exit(0)

print("IMPOSSIBLE")
