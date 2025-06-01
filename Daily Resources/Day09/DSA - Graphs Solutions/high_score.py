import sys
from collections import deque
input = sys.stdin.readline

INF = -10**15  # large negative number, similar to your C++ INF

n, m = map(int, input().split())
a = [0]*m
b = [0]*m
c = [0]*m

for i in range(m):
    a[i], b[i], c[i] = map(int, input().split())
    a[i] -= 1
    b[i] -= 1

dis = [INF]*n
dis[0] = 0

updatedNodes = []

for i in range(n+1):
    updated = False
    for j in range(m):
        if dis[a[j]] == INF:
            continue
        if dis[b[j]] < dis[a[j]] + c[j]:
            dis[b[j]] = dis[a[j]] + c[j]
            updated = True
            if i == n:
                updatedNodes.append(b[j])
    if not updated:
        break

if not updatedNodes:
    print(dis[n-1])
    sys.exit()

graph = [[] for _ in range(n)]
revGraph = [[] for _ in range(n)]

for i in range(m):
    graph[a[i]].append(b[i])
    revGraph[b[i]].append(a[i])

affected = [False]*n
q = deque()
for node in updatedNodes:
    if not affected[node]:
        affected[node] = True
        q.append(node)

while q:
    u = q.popleft()
    for v in graph[u]:
        if not affected[v]:
            affected[v] = True
            q.append(v)

reachableFromN = [False]*n
q2 = deque([n-1])
reachableFromN[n-1] = True

cycleAffectsN = False
while q2:
    u = q2.popleft()
    if affected[u]:
        cycleAffectsN = True
        break
    for v in revGraph[u]:
        if not reachableFromN[v]:
            reachableFromN[v] = True
            q2.append(v)

if cycleAffectsN:
    print(-1)
else:
    print(dis[n-1])
