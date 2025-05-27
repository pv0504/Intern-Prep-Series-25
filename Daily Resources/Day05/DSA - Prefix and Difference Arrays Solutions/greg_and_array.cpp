#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<tuple<int, int, int>> ops(m + 1);
    for (int i = 1; i <= m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        ops[i] = {l, r, d};
    }

    vector<long long> op_count(m + 2, 0); // For operation counts
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        op_count[x]++;
        op_count[y + 1]--;
    }

    // Prefix sum of operation counts
    for (int i = 1; i <= m; ++i)
        op_count[i] += op_count[i - 1];

    vector<long long> delta(n + 2, 0); // Difference array for `a`

    for (int i = 1; i <= m; ++i) {
        auto [l, r, d] = ops[i];
        long long total = d * op_count[i];
        delta[l] += total;
        delta[r + 1] -= total;
    }

    for (int i = 1; i <= n; ++i) {
        delta[i] += delta[i - 1];
        a[i] += delta[i];
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
