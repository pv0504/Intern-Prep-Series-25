#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, LOG = 20;
vector<int> tree[N];
int up[N][LOG], depth[N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i) {
        if (up[u][i-1] != -1)
            up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : tree[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; --i)
        if (depth[a] - (1 << i) >= depth[b])
            a = up[a][i];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != -1 && up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 2, b; i <= n; ++i) {
        cin >> b;
        tree[b].push_back(i);
    }

    dfs(1, -1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
