#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tree[N];

pair<int, int> dfs(int u, int parent, int dist) {
    pair<int, int> farthest = {dist, u};
    for (int v : tree[u]) {
        if (v != parent)
            farthest = max(farthest, dfs(v, u, dist + 1));
    }
    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int node = dfs(1, -1, 0).second;
    int diameter = dfs(node, -1, 0).first;
    cout << diameter << '\n';
}
