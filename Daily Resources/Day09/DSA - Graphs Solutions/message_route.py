from collections import deque

n, m = map(int, input().split())
adj = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)

par = [-1] * n
dis = [-1] * n
q = deque()
q.append(0)
dis[0] = 1  # distance from node 1 (index 0) is 1 (to match C++ output)

while q:
    x = q.popleft()
    for neighbor in adj[x]:
        if dis[neighbor] == -1:
            dis[neighbor] = dis[x] + 1
            par[neighbor] = x
            if neighbor == n - 1:
                break
            q.append(neighbor)

if dis[n - 1] == -1:
    print("IMPOSSIBLE")
else:
    print(dis[n - 1])
    path = []
    x = n - 1
    while x != 0:
        path.append(x + 1)  # convert to 1-based
        x = par[x]
    path.reverse()
    print(1, *path)
