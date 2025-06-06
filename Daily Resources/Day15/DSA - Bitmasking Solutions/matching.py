MOD = 10**9 + 7

def count_pairings(N, compatibility):
    dp = [0] * (1 << N)
    dp[0] = 1

    for mask in range(1 << N):
        k = bin(mask).count('1')  # number of men paired so far
        if k == N:
            continue
        for woman in range(N):
            if (mask & (1 << woman)) == 0 and compatibility[k][woman] == 1:
                dp[mask | (1 << woman)] = (dp[mask | (1 << woman)] + dp[mask]) % MOD

    return dp[(1 << N) - 1]

# Input reading
N = int(input())
compatibility = [list(map(int, input().split())) for _ in range(N)]

print(count_pairings(N, compatibility))
