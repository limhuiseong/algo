#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int max = *max_element(v.begin(), v.end());
	double result = 0.0;
	
	for (int i = 0; i < N; i++) {
		result += (double(v[i]) / double(max)) * 100.0;
	}
	
	cout << result / double(N) << '\n';
	
	return 0;
}