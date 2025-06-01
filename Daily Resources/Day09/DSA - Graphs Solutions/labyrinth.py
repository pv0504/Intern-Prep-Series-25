from collections import deque

n, m = map(int, input().split())
a = []
v = []
m1 = {}

for i in range(n):
    s = input().strip()
    a.append(s)
    t = []
    for j in range(m):
        if s[j] == 'A':
            ix, iy = i, j
        if s[j] == 'B':
            fx, fy = i, j
        if s[j] == '#':
            t.append(-2)
        else:
            t.append(-1)
    v.append(t)

v[ix][iy] = 0
q = deque()
q.append((ix, iy))

# Directions: up, left, down, right
dir_map = [(-1, 0, 'U'), (0, -1, 'L'), (1, 0, 'D'), (0, 1, 'R')]

found = False

while q:
    i, j = q.popleft()
    p2 = v[i][j]

    for dx, dy, move in dir_map:
        ni, nj = i + dx, j + dy
        if 0 <= ni < n and 0 <= nj < m and v[ni][nj] == -1:
            v[ni][nj] = p2 + 1
            m1[(ni, nj)] = move
            if (ni, nj) == (fx, fy):
                found = True
                break
            q.append((ni, nj))
    if found:
        break

if v[fx][fy] == -1:
    print("NO")
else:
    print("YES")
    print(v[fx][fy])
    ans = []
    i, j = fx, fy
    while (i, j) != (ix, iy):
        move = m1[(i, j)]
        ans.append(move)
        if move == 'U':
            i += 1
        elif move == 'L':
            j += 1
        elif move == 'D':
            i -= 1
        elif move == 'R':
            j -= 1
    print(''.join(reversed(ans)))
