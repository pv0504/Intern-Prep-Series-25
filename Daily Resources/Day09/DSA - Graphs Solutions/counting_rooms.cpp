#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
int m;
vector<string> a;
vector<vector<bool > > v;
 
 
void dfs (int i, int j)
{
    v[i][j] = true;
    if (i-1 >= 0 && v[i-1][j] == false)
    {
        dfs(i-1,j);
    }
    if (j-1 >= 0 && v[i][j-1] == false)
    {
        dfs(i,j-1);
    }
    if (i+1 < n && v[i+1][j] == false)
    {
        dfs(i+1,j);
    }
    if (j+1 < m && v[i][j+1] == false)
    {
        dfs(i,j+1);
    }
}
 
 
 
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    
    
    for (int i =  0 ;i < n ; i++)
    {
        vector<bool > t;
        string s;
        cin >> s;
        a.push_back(s);
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                t.push_back(false);
            }
            else
            {
                t.push_back(true);
            }
        }
        v.push_back(t);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == false)
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
