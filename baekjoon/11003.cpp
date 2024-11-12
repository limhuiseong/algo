#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int N, L;
deque<Node> my_deque;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;

        while (my_deque.size() && my_deque.back().first > now)
        {
            my_deque.pop_back();
        }
        my_deque.push_back(Node(now, i));

        if (my_deque.front().second <= i - L)
            my_deque.pop_front();      

        cout << my_deque.front().first << ' ';
    }

    return 0;
}