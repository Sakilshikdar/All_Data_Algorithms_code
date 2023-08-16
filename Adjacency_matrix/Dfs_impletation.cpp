#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
vector<int> adj[N];
bool visited[N];
int depth[N];

void dfs(int u)
{
    // cout << "visited node: " << u << endl;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);
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

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j : adj[i])
        {

            cout << j << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        cout << "depth of node " << i << ": " << depth[i] << endl;
    }

    return 0;
}

/*
9
10
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9
*/