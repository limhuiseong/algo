#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vector<int> n;
    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
    }
    int max_n = *max_element(n.begin(), n.end());

    vector<int> dp(12, 0);

    dp[1] = 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + 2;

    for (int i = 4; i <= max_n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (auto i: n) {
        cout << dp[i] << '\n';
    }

}