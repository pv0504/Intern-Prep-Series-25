import sys
sys.setrecursionlimit(2 * 10**5 + 10)

n = int(input())
tree = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

dp = [[0, 0] for _ in range(n + 1)]  # dp[u][0] = not matched, dp[u][1] = matched

def dfs(u, parent):
    for v in tree[u]:
        if v == parent:
            continue
        dfs(v, u)
        dp[u][0] += max(dp[v][0], dp[v][1])
    
    for v in tree[u]:
        if v == parent:
            continue
        dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1)

dfs(1, 0)
print(max(dp[1][0], dp[1][1]))
