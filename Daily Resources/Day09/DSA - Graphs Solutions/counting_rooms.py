from sys import stdin
from collections import deque

n, m = map(int, stdin.readline().split())
a = [stdin.readline().strip() for _ in range(n)]

# False means unvisited and '.' cell
visited = [[a[i][j] != '.' for j in range(m)] for i in range(n)]

def dfs_iterative(i, j):
    stack = [(i, j)]
    while stack:
        x, y = stack.pop()
        if visited[x][y]:
            continue
        visited[x][y] = True
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                stack.append((nx, ny))

ans = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            dfs_iterative(i, j)
            ans += 1

print(ans)
