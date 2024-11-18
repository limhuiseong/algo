#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator() (int a, int b)
    {
        int a_abs = abs(a);
        int b_abs = abs(b);

        if (a_abs == b_abs)
            return a > b;
        else
            return a_abs > b_abs;
    }
};

int N;
priority_queue<int, vector<int>, Compare> pq;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp == 0)
        {
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(tmp);
        }
    }

    return 0;
}