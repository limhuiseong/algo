#include <iostream>
#include <algorithm>

using namespace std;

int arr[50][50] = {0};
int ans = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 1; k < min(N, M); k++)
            {
                if (i + k < N && j + k < M)
                {
                    int target = arr[i][j];
                    if (arr[i][j + k] == target &&
                    arr[i + k][j] == target &&
                    arr[i + k][j + k] == target)
                    {
                        ans = max(ans, (k + 1) * (k + 1));
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}