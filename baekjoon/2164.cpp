#include <iostream>

using namespace std;

int N;

bool is_prime(int num)
{
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

void dfs(int num, int place)
{
    if (N == place)
    {
        if (is_prime(num))
            cout << num << "\n";
        return;
    }

    for (int i = 1; i < 10; i++)
    {
        if (i % 2 == 0)
            continue;
        if (is_prime(num * 10 + i))
            dfs(num * 10 + i, place + 1);
    }
}

void solve()
{
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solve();

    return 0;
}