#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    // dp[mask] = number of ways to pair men [0..k-1] with women in mask,
    // where k = number of set bits in mask.
    vector<long long> dp(1 << N, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); mask++) {
        int k = __builtin_popcount(mask);  // current man index to pair
        if (k == N) continue;

        for (int woman = 0; woman < N; woman++) {
            if ((mask & (1 << woman)) == 0 && a[k][woman] == 1) {
                int newMask = mask | (1 << woman);
                dp[newMask] = (dp[newMask] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1] << "\n";
    return 0;
}
