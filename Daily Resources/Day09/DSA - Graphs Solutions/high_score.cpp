#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
vector<int> dis;
int INF = -100000000000000;
vector<int> a, b, c;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    dis.assign(n, INF);
    a.resize(m);
    b.resize(m);
    c.resize(m);
 
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
 
    dis[0] = 0;
 
    vector<int> updatedNodes; // nodes updated on nth iteration
 
    for (int i = 0; i <= n; i++)
    {
        bool updated = false;
        for (int j = 0; j < m; j++)
        {
            if (dis[a[j]] == INF) continue;
            if (dis[b[j]] < dis[a[j]] + c[j])
            {
                dis[b[j]] = dis[a[j]] + c[j];
                updated = true;
                if (i == n)
                    updatedNodes.push_back(b[j]);
            }
        }
        if (!updated) break;
    }
 
    if (updatedNodes.empty()) {
        // No positive cycle affecting any node, print answer directly
        cout << dis[n - 1] << "\n";
        return 0;
    }
 
    // Build graph and reverse graph
    vector<vector<int>> graph(n);
    vector<vector<int>> revGraph(n);
    for (int i = 0; i < m; i++)
    {
        graph[a[i]].push_back(b[i]);
        revGraph[b[i]].push_back(a[i]);
    }
 
    // BFS from updatedNodes (nodes affected by positive cycles)
    vector<bool> affected(n, false);
    queue<int> q;
    for (int node : updatedNodes)
    {
        if (!affected[node])
        {
            affected[node] = true;
            q.push(node);
        }
    }
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : graph[u])
        {
            if (!affected[v])
            {
                affected[v] = true;
                q.push(v);
            }
        }
    }
 
    // BFS backwards from n-1 to see if we can reach any affected node
    vector<bool> reachableFromN(n, false);
    queue<int> q2;
    q2.push(n - 1);
    reachableFromN[n - 1] = true;
 
    bool cycleAffectsN = false;
    while (!q2.empty())
    {
        int u = q2.front(); q2.pop();
        if (affected[u])
        {
            cycleAffectsN = true;
            break;
        }
        for (int v : revGraph[u])
        {
            if (!reachableFromN[v])
            {
                reachableFromN[v] = true;
                q2.push(v);
            }
        }
    }
 
    if (cycleAffectsN)
        cout << -1 << "\n";
    else
        cout << dis[n - 1] << "\n";
 
    return 0;
}