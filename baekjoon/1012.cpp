#include <iostream>
#include <string.h>

#define BOX 50

using namespace std;

int graph[BOX][BOX] = {0};
bool visited[BOX][BOX] = {false};
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0 ,-1};

int M, N, K;

void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
        if (graph[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] == true;
            dfs(ny, nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> M >> N >> K;

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] && !visited[i][j])
                {
                    ans++;
                    visited[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
    
}