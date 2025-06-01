n, m = map(int, input().split())

adj = [[] for _ in range(n)]
vis = [False] * n

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

def dfs_iterative(start):
    stack = [start]
    vis[start] = True
    while stack:
        node = stack.pop()
        for neighbor in adj[node]:
            if not vis[neighbor]:
                vis[neighbor] = True
                stack.append(neighbor)

ans = -1
br = []

for i in range(n):
    if not vis[i]:
        if i != 0:
            br.append((1, i + 1))  # output is 1-based
        ans += 1
        dfs_iterative(i)

print(ans)
for u, v in br:
    print(u, v)
