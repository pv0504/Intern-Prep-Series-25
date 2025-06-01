#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    vector<vector<int> > adj;
    for (int i = 0; i < n; i++)
    {
    
        vector<int> c;
        adj.push_back(c);
    }
    for (int i = 0;i < m; i++)
    {
        cin >> a[i] >> b[i];
        adj[a[i]-1].push_back(b[i]-1);
        adj[b[i]-1].push_back(a[i]-1);
    }
    int par[n];
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    queue <int> q;
    q.push(0);
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = -1;
    }
    int ans = 0;
    dis[0] = 1;
    while (q.size() > 0)
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++)
        {
            if (dis[adj[x][i]] == -1)
            {
                dis[adj[x][i]] = dis[x] + 1;
                par[adj[x][i]] = x;
                if (adj[x][i] == n-1)
                {
                    break;
                }
                q.push(adj[x][i]);
            }
        }
    }
    if (dis[n-1] == -1)
        {
            cout << "IMPOSSIBLE" << endl;
        
        }
        else
        {
            cout << dis[n-1] << endl;
            vector<int> an;
            int x = n-1;
            while (x != 0)
            {
                an.push_back(x+1);
                x = par[x];
            }
            reverse(an.begin(), an.end());
            cout << 1 << " ";
            for (int i = 0; i < an.size(); i++)
            {
                cout << an[i] << " ";
            }
        }
 
 
}
