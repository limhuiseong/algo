#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;
vector<long long> A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        int start_idx = 0;
        int end_idx = N - 1;

        while (end_idx > start_idx)
        {
            if (start_idx == i)
            {
                start_idx++;
                continue;
            }
            else if (end_idx == i)
            {
                end_idx--;
                continue;
            }
            else if (A[i] == A[start_idx] + A[end_idx])
            {
                cnt++;
                break;
            }
            else if (A[i] > A[start_idx] + A[end_idx])
            {
                start_idx++;
            }
            else
            {
                end_idx--;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}