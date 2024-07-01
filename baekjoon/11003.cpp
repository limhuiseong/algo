#include <iostream>
#include <deque>

using namespace std;

int N, L;
deque<pair<int, int>> my_deque;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        while (my_deque.size() && my_deque.back().first > tmp)
        {
            my_deque.pop_back();
        }
        my_deque.push_back(pair<int, int>(tmp, i));
        if (my_deque.front().second <= i - L)
        {
            my_deque.pop_front();
        }
        cout << my_deque.front().first << ' ';
    }

    return 0;
}