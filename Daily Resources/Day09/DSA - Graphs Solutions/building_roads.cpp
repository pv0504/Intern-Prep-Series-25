#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> vis;
int n, m;
    set<pair<int,int> > adj;
void dfs(int a)
{
    vis[a] = true;
    auto it = adj.lower_bound(make_pair(a, 0));
    if (it == adj.end())
    {
        return;
    }
    while (it != adj.end() && (*it).first == a)
    {
        if (vis[(*it).second] == true)
 
        {
            it++;
            continue;
        }
 
        vis[(*it).second] = true;
 
        dfs((*it).second);
        it++;
    }
}
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int a[m], b[m];
 
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        adj.insert(make_pair(a[i]-1, b[i]-1));
        adj.insert(make_pair(b[i]-1, a[i]-1));
    }
    for (int i = 0; i < n; i++)
    {
        vis.push_back(false);
    }
    int ans = -1;
    vector< pair<int,int> > br;
    for (int i = 0; i < n; i++)
    {
 
        if (vis[i] == true)
        {
            continue;
        }
        else
        {
 
            if (i != 0)
            br.push_back(make_pair(1, i+1));
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < br.size(); i++)
    {
        cout << br[i].first << " " << br[i].second << endl;
    }
    
    
}
 
