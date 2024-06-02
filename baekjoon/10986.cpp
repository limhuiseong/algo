#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	vector<long> S(N + 1, 0);
	vector<long> C(M, 0);
	
	long cnt = 0;
	
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		S[i] = S[i - 1] + tmp;
		
		if (S[i] % M == 0) cnt++;
		C[S[i] % M]++;
	}
	
	for (int i = 0; i < M; i++) {
		if (C[i] > 1)
			cnt += (C[i] * (C[i] - 1) / 2);
	}
	
	cout << cnt << '\n';
	
	return 0;
}