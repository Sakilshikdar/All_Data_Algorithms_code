#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
int level[n];
vector<int> adj[n];
bool visited[n];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    bfs(q);
    int dc = 0;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == 1)
        {
            dc++;
        }
    }

    cout << dc << endl;
    return 0;
}