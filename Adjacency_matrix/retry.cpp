#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    // cout << "visited Node: " << u << endl;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        depth[v] = depth[u] + 1;
        // if (height[v] + 1 > height[u])
        // {
        //     height[u] = height[v] + 1;
        // }
        height[u] = max(height[u], height[v] + 1);
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
        // adj[v].push_back(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "depth of " << i << ": ";
        cout << depth[i];
        cout << endl;
    }
    cout << "-----------------------------\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "height of " << i << ": ";
        cout << height[i];
        cout << endl;
    }

    return 0;
}

/*
9
10
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9
*/