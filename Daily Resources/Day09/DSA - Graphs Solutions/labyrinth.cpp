#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
int m;
 
vector<string> a;
int fx, fy;
vector<vector<int> > v;
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int ix, iy;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
        vector<int> t;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                ix = i;
                iy = j;
            }
            if (a[i][j] == 'B')
            {
                fx = i;
                fy = j;
            }
            if (a[i][j] == '#')
            {
                t.push_back(-2);
            }
            else
            {
                t.push_back(-1);
            }
        }
        v.push_back(t);
    }
    v[ix][iy] = 0;
    queue <pair<int,int> > q;
    map<pair<int,int> , char> m1;
    q.push(make_pair(ix,iy));
    while (q.size() != 0)
    {
        pair<int,int> p1 = q.front();
        q.pop();
        int i = p1.first;
        int j = p1.second;
        int p2 = v[i][j];
        if (i-1 >= 0 && v[i-1][j] == -1)
        {
            
            v[i-1][j] = p2+1;
            m1[make_pair(i-1, j)] = 'U';
            if (i-1 == fx && j == fy)
 
            {
                break;
            }
            q.push(make_pair(i-1,j));
        }
        if (j-1 >= 0 && v[i][j-1] == -1)
        {
            v[i][j-1] = p2+1;
            m1[make_pair(i, j-1)] = 'L';
            if (i == fx && j-1 == fy)
            {
                break;
            }
            q.push(make_pair(i,j-1));
        }
        if (i+1 < n && v[i+1][j] == -1)
        {
            v[i+1][j] = p2+1;
            m1[make_pair(i+1, j)] = 'D';
            if (i+1 == fx && j == fy)
            {
                break;
            }
            q.push(make_pair(i+1,j));
        }
        if (j+1 < m && v[i][j+1] == -1)
        {
            v[i][j+1] = p2+1;
            m1[make_pair(i, j+1)] = 'R';
            if (i == fx && j+1 == fy)
            {
                break;
            }
            q.push(make_pair(i,j+1));
        }
    }
    if (v[fx][fy] == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << v[fx][fy] << endl;
        vector<char> ans;
        int i = fx;
        int j = fy;
        while (i != ix || j != iy)
        {
            char move = m1[make_pair(i,j)];
            ans.push_back(move);
            if (move == 'U') i++;
            else if (move == 'L') j++;
            else if (move == 'D') i--;
            else if (move == 'R') j--;
        }
        reverse(ans.begin(), ans.end());
        for (char c : ans)
        {
            cout << c;
        }
        cout << endl;
    }
 
    
     
    
 
}
