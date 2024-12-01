#include <iostream>
#include <queue>

using namespace std;

static int n, m;
static int A[101][101];
static bool visited[101][101];
static int dx[4] = {0, 1, 0, -1};
static int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y)
{
    queue<pair<int, int>> my_queue;
    my_queue.push(make_pair(x, y));

    while (!my_queue.empty())
    {
        int now[2] = {my_queue.front().first, my_queue.front().second};
        my_queue.pop();
        visited[x][y] = visited[x][y] ^ 1;

        for (int i = 0; i < 4; i++)
        {
            int x = now[0] + dx[i];
            int y = now[1] + dy[i];

            if (x >= 1 && y >= 1 & x <= n && y <= m)
            {
                if (A[x][y] != 0 && !visited[x][y])
                {
                    visited[x][y] = true;
                    A[x][y] = A[now[0]][now[1]] + 1;
                    my_queue.push(make_pair(x, y));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < 101; i++)
    {
        visited[i][0] = true;
        visited[0][i] = true;
    }

    for (int i = 1; i < n + 1; i++) {
        string row;
        cin >> row;
        for (int j = 1; j < m + 1; j++) {
            A[i][j] = row[j - 1] - '0';
        }
    }

    bfs(1, 1);
    cout << A[n][m] << "\n";

    return 0;
}