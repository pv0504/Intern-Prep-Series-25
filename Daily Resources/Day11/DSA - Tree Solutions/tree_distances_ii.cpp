#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tree[N];
long long int subsize[N], res[N], n;

void dfs1(int u, int parent) {
    subsize[u] = 1;
    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        subsize[u] += subsize[v];
        res[u] += res[v] + subsize[v];
    }
}

void dfs2(int u, int parent) {
    for (int v : tree[u]) {
        if (v == parent) continue;
        res[v] = res[u] - subsize[v] + (n - subsize[v]);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";
}
