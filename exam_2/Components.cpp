#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

int dfs(int u)
{
    visited[u] = true;
    int size = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            size = size + dfs(v);
        }
    }
    return size;
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

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int size = dfs(i);
            if (size > 1)
            {
                v.push_back(size);
            }
        }
    }

    sort(v.begin(), v.end());

    for (int size : v)
    {
        cout << size << " ";
    }

    return 0;
}
