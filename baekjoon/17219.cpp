#include <iostream>
#include <map>

using namespace std;

map<string, string> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		m.insert(make_pair(tmp1, tmp2));
	}
	
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		cout << m[tmp] << '\n';
	}
	
}