#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
vector<int> col;
vector<vector<int> > adj;
 
 
bool dfs (int i)
{
    for (int c : adj[i])
    {
        if (col[c] == -1 )
        {
             col[c] = (col[i]+1)%2 ;
             bool x = dfs(c);
             if (x == false)
             {
                return false;
             }
        }
        else if ( col[c] == (col[i]+1)%2 )
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
 
    cin >> n >> m;
 
 
    for (int i = 0; i < n; i++ )
    {
        vector<int> x;
        adj.push_back(x);
        col.push_back(-1);
    }
    
    for (int i = 0; i < m; i++)
    {
        int x , y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            col[i] = 0;
            bool x = dfs(i);
            if (!x)
            {
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
    
    
        for (int x : col)
        {
            cout << x + 1 << " ";
        }
 
    
}
 
