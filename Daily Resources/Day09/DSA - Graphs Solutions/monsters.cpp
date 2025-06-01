#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<string > mtx;
int n, m;
 
signed main()
{
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mtx.push_back(s);
    }
    vector<vector<int> > adj;
    queue <int> qm;
    int dism[n][m];
    queue <int> q;
    int dis[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // vector<int> x;
            dism[i][j] = -1;
            dis[i][j] = -1;
            if (mtx[i][j] == 'M')
            {
                dism[i][j] = 0;
                qm.push(i*m+j);
            }
            if (mtx[i][j] == 'A')
            {
                dis[i][j] = 0;
                q.push(i*m+j);
            }
            if (mtx[i][j] == '#')
            {
                continue;
            }
        }
    }
    while (qm.size() > 0)
    {
        int in = qm.front();
        qm.pop();
        int i = in/m;
        int j = in%m;
        if (i-1 >= 0 && mtx[i-1][j] != '#')
        {
            if (dism[i-1][j] == -1)
            {
                qm.push((i-1)*m + j);
                dism[i-1][j] = dism[i][j]+1;
            }
            
        }
        if (j-1 >= 0 && mtx[i][j-1] != '#')
        {
            if (dism[i][j-1] == -1)
            {
                qm.push((i)*m + j-1);
                dism[i][j-1] = dism[i][j]+1;
            }
        }
        if (i+1 < n && mtx[i+1][j] != '#')
        {
            if (dism[i+1][j] == -1)
            {
                qm.push((i+1)*m + j);
                dism[i+1][j] = dism[i][j]+1;
            }
        }
        if (j+1 < m && mtx[i][j+1] != '#')
        {
            if (dism[i][j+1] == -1)
            {
                qm.push((i)*m + j+1);
                dism[i][j+1] = dism[i][j]+1;
            }
        }
    }
    map<int,int> par;
    int x2 = q.front();
    int x1 = x1/m;
    int y1 = x1%m;
    par[x2] = -1;
    while (q.size() > 0)
    {
        int in = q.front();
        q.pop();
        int i = in/m;
        int j = in%m;
        if (i-1 >= 0 && mtx[i-1][j] != '#')
        {
            if (dis[i-1][j] == -1)
            {
                par[(i-1)*m + j] = i*m+j;
                q.push((i-1)*m + j);
                dis[i-1][j] = dis[i][j]+1;
            }
            
        }
        if (j-1 >= 0 && mtx[i][j-1] != '#')
        {
            if (dis[i][j-1] == -1)
            {
                par[(i)*m + j-1] = i*m+j;
                dis[i][j-1] = dis[i][j]+1;
                q.push((i)*m + j-1);
                
            }
        }
        if (i+1 < n && mtx[i+1][j] != '#')
        {
            if (dis[i+1][j] == -1)
            {
                par[(i+1)*m + j] = i*m+j;
                q.push((i+1)*m + j);
                dis[i+1][j] = dis[i][j]+1;
            }
        }
        if (j+1 < m && mtx[i][j+1] != '#')
        {
            if (dis[i][j+1] == -1)
            {
                par[(i)*m + j+1] = i*m+j;
                q.push((i)*m + j+1);
                dis[i][j+1] = dis[i][j]+1;
            }
        }
    }
        pair<int, int> escape = make_pair(-1,-1);
    for (int j = 0; j < m; j++) {
        if (dis[0][j] != -1 && (dis[0][j] < dism[0][j] || dism[0][j] == -1))
            escape = make_pair(0, j);
        if (dis[n-1][j] != -1 && (dis[n-1][j] < dism[n-1][j] || dism[n-1][j] == -1))
            escape = make_pair(n-1,j);
    }
    for (int i = 0; i < n; i++) {
        if (dis[i][0] != -1 && (dis[i][0] < dism[i][0] || dism[i][0] == -1))
            escape = make_pair(i,0);
        if (dis[i][m-1] != -1 && (dis[i][m-1] < dism[i][m-1] || dism[i][m-1] == -1))
            escape = make_pair(i,m-1);
    }
 
    if (escape.first == -1) {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    int i = escape.first, j = escape.second;
    vector<char> path;
    while (mtx[i][j] != 'A') {
        int pi = par[i * m + j] / m;
        int pj = par[i * m + j] % m;
        if (pi == i - 1) path.push_back('D');
        else if (pi == i + 1) path.push_back('U');
        else if (pj == j - 1) path.push_back('R');
        else if (pj == j + 1) path.push_back('L');
        i = pi;
        j = pj;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (char c : path) cout << c;
    cout << '\n';
 
 
 
}
 
