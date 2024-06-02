#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> A;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());
	
	int start_idx = 0, end_idx = N - 1;
	int sum = 0;
	int cnt = 0;
	
	while (start_idx < end_idx) {
		int tmp = A[start_idx] + A[end_idx];
		if (tmp == M) {
			cnt++;
			start_idx++;
			end_idx--;
		}
		else if (tmp > M) end_idx--;
		else start_idx++;
	}
	
	cout << cnt << '\n';
	
	return 0;
}