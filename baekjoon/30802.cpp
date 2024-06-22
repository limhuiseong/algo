#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;    
    int size[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> size[i];
    }
    int T, P;
    cin >> T >> P;

    int a = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        if (size[i] % T != 0)
        {
            a += (int)(size[i] / T) + 1;
        }
        else
        {
            a += size[i] / T;
        }
        sum += size[i];
    }
    cout << a << '\n';

    cout << (int)(sum / P) << ' ' << sum % P;
}