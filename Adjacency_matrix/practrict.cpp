/*
Question: You will be given an undirected graph. Print its DFS traversal in reverse order. Consider root as 1.
Sample Input
Sample Output
4
4
1 2
4 3
3 2
2 4
3 4 2 1
( 4 3 2 1 is also valid ans)
*/

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// vector<int> adj[N];
// bool visited[N];

// void dfs(int u)
// {
//     visited[u] = true;

//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         dfs(v);
//     }
//     cout << u << " ";
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs(1);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int v : adj[i])
//     //     {
//     //         cout << v << " ";
//     //     }
//     // }

//     return 0;
// }

/*
Question: You will be given an adjacency matrix for a directed graph (index starting from 1) as input. Now, convert it to an adjacency list and print it.

Sample Input
Sample Output

4
0 0 0 1
1 0 0 1
1 1 0 0
0 0 1 0

List 1 : 4
List 2 : 1 4
List 3 : 1 2
List 4 : 3

5
0 0 0 0 0
1 0 0 1 1
1 1 0 1 1
1 1 1 0 0
0 0 1 0 0

List 1 :
List 2 : 1 4 5
List 3 : 1 2 4 5
List 4 : 1 2 3
List 5 : 3
*/

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3 + 5;
// vector<int> adj[N];
// bool visited[N];

// void dfs(int u)
// {
//     visited[u] = true;

//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         dfs(v);
//     }
//     cout << u << " ";
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs(1);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int v : adj[i])
//     //     {
//     //         cout << v << " ";
//     //     }
//     // }

//     return 0;
// }

/*
Question: You will be given a directed graph as input. Store this graph in an adjacency list. Now, convert this adjacency list to an adjacency matrix (index starting from 1) and print it. Consider root as 1.
Sample Input
Sample Output
3
5
1 2
2 3
1 3
3 1
3 2
0 1 1
0 0 1
1 1 0
*/

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// int adjmat[N][N];

// int main()
// {

//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adjmat[u][v] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << adjmat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

/*
Question: You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its depth. Consider root as 1.

Sample Input
Sample Output
7
6
1 2
2 4
2 5
1 3
3 6
1 7
7
Depth of 7 = 1
7
6
1 2
2 4
2 5
1 3
3 6
1 7
4
Depth of 4 = 2
*/

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// vector<int> adj[N];
// int visited[N];
// int height[N];

// void dfs(int u)
// {
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         dfs(v);
//         height[u] = max(height[u], height[v] + 1);
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs(1);
//     int x;
//     cin >> x;
// for (int i = 1; i <= n; i++)
// {
//     if (x == i)
//     {
// cout << x << ":" << height[x] << endl;
// break;
//     }
// }
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int adjmat[N][N];

void dfs(int u)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
    cout << u << " ";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjmat[i][j];
            if (adjmat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}