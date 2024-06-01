#include <iostream>

using namespace std;

int main() {
	int N = 0;
	cin >> N;
	
	string s;
	cin >> s;
	
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';
	
	cout << sum << '\n';
	
	return 0;
}