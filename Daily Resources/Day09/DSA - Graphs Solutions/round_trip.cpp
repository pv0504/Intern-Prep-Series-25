#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> > adj;
int n, m;
vector<int> par;
vector<bool> vis;
 
int dfs(int a)
{
    vis[a] = true;
    for (int c : adj[a])
    {
        if (par[a] == c)
        {
            continue;
        }
        if (vis[c] == true && par[a] != c)
        {
            par[c] = a;
            return c;
        }
        else
        {
             par[c] = a;
            int x = dfs(c);
           
            if (x != -1)
            return x;
        }
    }
    return -1;
}
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> c;
        adj.push_back(c);
        vis.push_back(false);
        par.push_back(-1);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for (int i = 0 ; i < n; i++)
    {
        if (vis[i] == false)
        {
            int x = dfs(i);
            if (x != -1)
            {
                vector<int> y;
                int z = x;
                y.push_back(x);
                x = par[x];
                
                while (z != x)
                {
                    y.push_back(x);
                    x = par[x];
                }
                y.push_back(x);
                cout << y.size() << endl;
                for (int ab : y)
                {
                    cout << ab +1 <<  " ";
                }
                exit(0);
            }
        }
    }
    
        cout << "IMPOSSIBLE";
 
   
        
    
}
 