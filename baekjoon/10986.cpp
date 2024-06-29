// (A + B) % C = ((A % C) + (B % C)) % C
// if S[j] % M == S[i] % M
// then (S[j] - S[i]) % M = 0

#include <iostream>

using namespace std;

int N, M;
long long A[1000001];
long long S[1000001];

long long C[1000001];
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		S[i] = S[i - 1] + A[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (S[i] % M == 0) ans++;
		C[S[i] % M]++;
	}

	for (int i = 0; i < M; i++)
	{
		if (C[i] > 1)
			ans += C[i] * (C[i] - 1) / 2;
	}

	cout << ans << '\n';
    return 0;
}