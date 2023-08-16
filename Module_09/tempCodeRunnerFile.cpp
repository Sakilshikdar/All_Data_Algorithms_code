vector<int> av;
bool visited[N];
int level[N];
int paraent[N];

void bfs(int s)
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
    paraent[s] = -1;
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
            paraent[v] = u;
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

    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "distance" << level[d] << endl;
    // for (int i = 1; i <= n; i++)
    // {