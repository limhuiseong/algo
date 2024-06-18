#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long long> step(N + 1);
    vector<long long> dp(N + 1);

    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        step[i] = tmp;
    }

    dp[1] = step[1];
    dp[2] = dp[1] + step[2];
    dp[3] = step[3] + max(step[1], step[2]); 

    for (int i = 4; i <= N; i++){
        dp[i] = step[i] + max(dp[i - 3] + step[i - 1], dp[i - 2]);
    }

    cout << dp[N]<< '\n';
}