#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void dfs(int x) {
	if (visited[x]) return;
	
	visited[x] = true;
	for (int i : A[x]) {
		if (!visited[i])
			dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		A[u].push_back(v);
		A[v].push_back(u);
	}
	
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}