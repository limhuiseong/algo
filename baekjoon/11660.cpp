#include <iostream>

using namespace std;

int N, M;
int A[1025][1025];
int D[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
		}
	}

	for (int p = 0; p < M; p++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// int ans = D[y2][x2] - D[y2][x1 - 1] - D[y1 - 1][x2] + D[y1 - 1][x1 - 1];
		int ans = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}


    return 0;
}