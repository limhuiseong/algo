#include <iostream>

using namespace std;

int N;
int cnt = 1;
int front_idx = 1;
int end_idx = 1;
int sum = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;

	while (end_idx != N)
	{
		if (sum == N)
		{
			cnt++;
			sum += ++end_idx;
		}
		else if (sum > N)
		{
			sum -= front_idx++;
		}
		else
		{
			sum += ++end_idx;
		}
	}

	cout << cnt << '\n';
	
    return 0;
}