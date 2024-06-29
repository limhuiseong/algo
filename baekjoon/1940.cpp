#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
int cnt = 0;
int start_idx = 0;
int end_idx;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> M;
	end_idx = N - 1;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());

	while (end_idx > start_idx)
	{
		int sum_of_idx = A[start_idx] + A[end_idx];
		if (sum_of_idx == M)
		{
			cnt++;
			end_idx--;
		}
		else if (sum_of_idx > M)
		{
			end_idx--;
		}
		else
		{
			start_idx++;
		}
	}

	cout << cnt << '\n';
    return 0;
}