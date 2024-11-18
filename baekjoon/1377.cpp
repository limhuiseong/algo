#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int max_loc = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (max_loc < A[i].second - i)
            max_loc = A[i].second - i;
    }

    cout << max_loc + 1 << "\n";
}