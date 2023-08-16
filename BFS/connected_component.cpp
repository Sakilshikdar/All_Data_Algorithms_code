#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
vector<int> adj[n];
vector<int> com[n];
int row = 0;
bool visited[n];
void dfs(int u)
{
    visited[u] = true;
    com[row].push_back(u);
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        /* code */
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs(1);
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
        row++;
    }
    for (int i = 0; i < row; i++)
    {
        cout << "component of " << i + 1 << " : ";
        for (int v : com[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << cc;
    return 0;
}