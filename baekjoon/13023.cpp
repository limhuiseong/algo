#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

int N, M;
int cnt = 0;

bool dfs(int v, int depth)
{
    if (depth == 5)
        return true;

    visited[v] = true;

    for (int i: A[v])
        if (!visited[i])
            if (dfs(i, depth + 1))
                return true;

    visited[v] = false;
    return false;
}

void solve()
{
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        if (dfs(i ,1))
        {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    solve();

    return 0;
}