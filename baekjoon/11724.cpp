#include <iostream>
#include <vector>

using namespace std;

int N, M;
static vector<vector<int>> A;
static vector<bool> visited;
int cnt = 0;

void DFS(int v)
{
	if (visited[v])
		return;
	visited[v] = true;

	for (int i : A[v])
	{
		if (!visited[i])
			DFS(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M; 
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			cnt++;
			DFS(i);
		}
	}

	cout << cnt << "\n";

	return 0;
}