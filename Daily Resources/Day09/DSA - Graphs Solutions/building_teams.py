from collections import deque
import sys
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())

adj = [[] for _ in range(n)]
col = [-1] * n  # color array

for _ in range(m):
    x, y = map(int, input().split())
    adj[x - 1].append(y - 1)
    adj[y - 1].append(x - 1)

def bfs(start):
    queue = deque([start])
    while queue:
        i = queue.popleft()
        for c in adj[i]:
            if col[c] == -1:
                col[c] = (col[i] + 1) % 2
                queue.append(c)
            elif col[c] == col[i]:
                return False
    return True

for i in range(n):
    if col[i] == -1:
        col[i] = 0
        if not bfs(i):
            print("IMPOSSIBLE")
            sys.exit()

print(' '.join(str(c + 1) for c in col))
