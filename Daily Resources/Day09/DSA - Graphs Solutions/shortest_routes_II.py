import sys
input = sys.stdin.readline
INF = 10**18

n, m, q = map(int, input().split())
dist = [[INF]*n for _ in range(n)]
for i in range(n):
    dist[i][i] = 0

for _ in range(m):
    a,b,c = map(int, input().split())
    a -= 1; b -= 1
    if c < dist[a][b]:
        dist[a][b] = c
        dist[b][a] = c

# Cache local variables for speed
dist_i = dist
range_n = range(n)

for k in range_n:
    dist_k = dist_i[k]
    for i in range_n:
        dist_i_i = dist_i[i]
        dist_i_i_k = dist_i_i[k]
        for j in range_n:
            val = dist_i_i_k + dist_k[j]
            if val < dist_i_i[j]:
                dist_i_i[j] = val

write = sys.stdout.write
for _ in range(q):
    a,b = map(int, input().split())
    a -= 1; b -= 1
    ans = dist[a][b]
    write(str(ans if ans < INF else -1) + '\n')
