#include <iostream>
#include <vector>

using namespace std;

vector<int> A, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
		if (i != 0)
			S.push_back(S[i - 1] + tmp);
		else
			S.push_back(tmp);
	}
	
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) cout << S[y - 1] << '\n';
		else if (x == y) cout << A[y - 1] << '\n';
		else cout << S[y - 1] - S[x - 2] << '\n';
	}
	
	return 0;
}