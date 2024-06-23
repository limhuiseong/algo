#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> operands;
int operators[4];

long long mmin = 1000000001;
long long mmax = -1000000001;

void solve(long long result, int idx)
{
    if (idx == N)
    {
        if (result > mmax) mmax = result;
        if (result < mmin) mmin = result;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
            {
                solve(result + operands[idx], idx + 1);
            }
            else if (i == 1)
            {
                solve(result - operands[idx], idx + 1);
            }
            else if (i == 2)
            {
                solve(result * operands[idx], idx + 1);
            }
            else
            {
                solve(result / operands[idx], idx + 1);
            }
            operators[i]++;
        }
    }
    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        operands.push_back(tmp);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }
    solve(operands[0], 1);
    cout << mmax << '\n' << mmin << '\n';
}