#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3];

int main()
{
    int N;
    cin >> N;

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp[3];
        cin >> tmp[0] >> tmp[1] >> tmp[2];

        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + tmp[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + tmp[1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + tmp[2]; 
    }
    
    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << '\n';
}
