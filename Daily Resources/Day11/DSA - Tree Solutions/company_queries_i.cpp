#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, LOG = 20;
int up[N][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    up[1][0] = -1;

    for (int i = 2; i <= n; ++i) {
        cin >> up[i][0];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
            else
                up[i][j] = -1;
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < LOG && x != -1; ++i) {
            if (k & (1 << i))
                x = up[x][i];
        }
        cout << x << '\n';
    }
}
