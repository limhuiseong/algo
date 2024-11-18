#include <iostream>

using namespace std;

int N;
int numbers[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int tmp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << numbers[i] << "\n";

    return 0;
}