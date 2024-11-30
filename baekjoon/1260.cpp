#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, v;

static vector<vector<int>> D;
static vector<bool> visited;

void bfs(int node)
{
    queue<int> my_queue;
    my_queue.push(node);
    visited[node] = true;

    while (!my_queue.empty())
    {
        int now = my_queue.front();
        my_queue.pop();
        
        cout << now << " ";

        for (int i: D[now])
        {
            if (!visited[i])
            {
                visited[i] = true;
                my_queue.push(i);
            }
        }
    }
}

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;

    cout << node << " ";

    for (int i: D[node])
    {
        dfs(i);
    }
    
}

void solve()
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        D[u].push_back(v);
        D[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(D[i].begin(), D[i].end());
    }

    dfs(v);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);

    bfs(v);
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;
    D.resize(n + 1);
    visited = vector<bool>(n + 1, false);

    solve();

    return 0;
}