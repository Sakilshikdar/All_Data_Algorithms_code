#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int adj[N][N];
bool visited[N];
int t;

void dfs(int node)
{
    visited[node] = true;
    t++;

    for (int i = 0; i < N; i++)
    {
        if (adj[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A][B] = 1;
    }

    int K;
    cin >> K;

    t = 0;
    dfs(K);

    int rh = t - 1;

    cout << rh << endl;

    return 0;
}
