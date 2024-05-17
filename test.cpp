#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0), deg(n, 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a = a - 1, b = b - 1;
        if (!vis[a] && !vis[b])
            adj.push_back({a, b});
        else
        {
            for (int i = 0; i < adj.size(); i++)
            {

                if (find(adj[i].begin(), adj[i].end(), a) != adj[i].end() && find(adj[i].begin(), adj[i].end(), b) == adj[i].end())
                    adj[i].push_back(b);
                else if (find(adj[i].begin(), adj[i].end(), b) != adj[i].end() && find(adj[i].begin(), adj[i].end(), a) == adj[i].end())
                    adj[i].push_back(a);
            }
        }
        vis[a] = 1, vis[b] = 1;
        deg[a]++;
        deg[b]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            adj.push_back({i});
    }
    vector<int> st(n, 0);
    int ans = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (deg[adj[i][j]] != 1)
                count++;
        }
        if (count == 1)
        {
            st[adj[i].size()]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}