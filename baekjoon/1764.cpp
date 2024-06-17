#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
map<string, int> r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		m.insert(make_pair(tmp, i + 1));
	}
	
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		if (m[tmp] != 0) {
			r.insert(make_pair(tmp, i));
			cnt++;
		}
	}
	
	cout << cnt << '\n';
	for (auto i: r) {
		cout << i.first << '\n';
	}
	
}