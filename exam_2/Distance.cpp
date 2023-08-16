#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int level[N];
vector<int> adj[N];
bool visited[N];

void bfs(int s)
{
    // cout << s << " ";
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
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
            level[i] = 0;
        }
        bfs(a);
        if (visited[b])
        {
            cout << level[b] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        // cout << i << " " << level[i] << endl;
    }
    return 0;
}