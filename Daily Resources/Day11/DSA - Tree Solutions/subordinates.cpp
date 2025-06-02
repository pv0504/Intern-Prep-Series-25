#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> res;

int dfs(int u) {
    for (int v : tree[u])
        res[u] += 1 + dfs(v);
    return res[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    tree.resize(n + 1);
    res.resize(n + 1);

    for (int i = 2, b; i <= n; ++i) {
        cin >> b;
        tree[b].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";
}
