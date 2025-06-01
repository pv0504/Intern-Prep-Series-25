from collections import deque

n, m = map(int, input().split())
mtx = [input().strip() for _ in range(n)]

dism = [[-1] * m for _ in range(n)]
dis = [[-1] * m for _ in range(n)]
par = [[None] * m for _ in range(n)]

# Directions with corresponding characters
dirs = [(-1,0), (1,0), (0,-1), (0,1)]
dir_char = {(-1,0): 'U', (1,0): 'D', (0,-1): 'L', (0,1): 'R'}

# Queues for BFS
qm = deque()
q = deque()

# Initialize BFS for monsters and player
for i in range(n):
    for j in range(m):
        if mtx[i][j] == 'M':
            dism[i][j] = 0
            qm.append((i, j))
        elif mtx[i][j] == 'A':
            dis[i][j] = 0
            q.append((i, j))
            start = (i, j)

# Multi-source BFS for monsters
while qm:
    i, j = qm.popleft()
    for dx, dy in dirs:
        ni, nj = i + dx, j + dy
        if 0 <= ni < n and 0 <= nj < m and mtx[ni][nj] != '#' and dism[ni][nj] == -1:
            dism[ni][nj] = dism[i][j] + 1
            qm.append((ni, nj))

# BFS for player
while q:
    i, j = q.popleft()
    for dx, dy in dirs:
        ni, nj = i + dx, j + dy
        if 0 <= ni < n and 0 <= nj < m and mtx[ni][nj] != '#' and dis[ni][nj] == -1:
            if dism[ni][nj] == -1 or dis[i][j] + 1 < dism[ni][nj]:
                dis[ni][nj] = dis[i][j] + 1
                par[ni][nj] = (i, j, dx, dy)
                q.append((ni, nj))

# Check for escape on the border
for i in range(n):
    for j in [0, m - 1]:
        if dis[i][j] != -1 and (dism[i][j] == -1 or dis[i][j] < dism[i][j]):
            escape = (i, j)
            break
    else:
        continue
    break
else:
    for j in range(m):
        for i in [0, n - 1]:
            if dis[i][j] != -1 and (dism[i][j] == -1 or dis[i][j] < dism[i][j]):
                escape = (i, j)
                break
        else:
            continue
        break
    else:
        print("NO")
        exit()

# Reconstruct path
path = []
i, j = escape
while (i, j) != start:
    pi, pj, dx, dy = par[i][j]
    path.append(dir_char[(dx, dy)])
    i, j = pi, pj

print("YES")
print(len(path))
print(''.join(reversed(path)))
