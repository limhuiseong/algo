#include <iostream>

using namespace std;

long long dp[1001] = {0};

int main()
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;

    for (int i = 5; i <= 1001; i++)
    {
        dp[i] = (dp[i - 1] + dp[i -2]) % 10007;
    }

    cout << dp[n]<< '\n';
}