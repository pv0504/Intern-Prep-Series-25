#include <bits/stdc++.h>
using namespace std;
#define int long long
 
    int n,m;
    vector<vector<pair<int,int> > > adj;
    vector<vector<int> > dis;
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        vector<pair<int,int> > x;
        adj.push_back(x);
        vector<int> y;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                y.push_back(0);
            }
            else
            {
                y.push_back(-1);
            }
        }
        dis.push_back(y);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x-1].push_back(make_pair(y-1,z));
        adj[y-1].push_back(make_pair(x-1,z));
        if (dis[x-1][y-1] < z && dis[x-1][y-1] != -1)
        {
            continue;
        }
        dis[x-1][y-1] = z;
        dis[y-1][x-1] = z;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dis[j][i] == -1 || dis[i][k] == -1)
                {
                    continue;
                }
                if (dis[j][k] > dis[j][i] + dis[i][k] || dis[j][k] == -1)
                {
                    dis[j][k] = dis[j][i] + dis[i][k];
             
                }
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dis[x-1][y-1] << endl;
    }
}
 
