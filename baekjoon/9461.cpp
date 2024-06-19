#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<long long> dp(101, 0);
    vector<int> N;

    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;
        N.push_back(tmp);
    }

    int max_N = *max_element(N.begin(), N.end());

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    dp[6] = 3;

    for (int i = 7; i <= max_N; i++) {
        dp[i] = dp[i - 2] + dp[i - 3]; 
    }

    for (auto i: N) {
        cout << dp[i] << '\n';
    }
}