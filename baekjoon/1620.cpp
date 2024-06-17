#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int> s;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		s.insert(make_pair(tmp, i));
		v.push_back(tmp);
	}
	
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		
		int first = int(tmp[0] - '0');
		if (0 < first && first <= 9) {
			int tmp_int = stoi(tmp);
			cout << v[tmp_int - 1] << '\n';
		}
		else {
			cout << s[tmp] + 1 << '\n';
		}
	}
	
	return 0;
}