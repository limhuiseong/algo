#include <iostream>

using namespace std;

int S;
int P;
string DNA;
int condition[4];
int current[4];
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> P;
    cin >> DNA;
    for (int i = 0; i < 4; i++)
    {
        cin >> condition[i];
    }

    for (int i = 0; i < P; i++)
    {
        switch (DNA[i])
        {
            case 'A':
                current[0]++;
                break;
            case 'C':
                current[1]++;
                break;
            case 'G':
                current[2]++;
                break;
            case 'T':
                current[3]++;
                break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (current[i] < condition[i])
            break;
        if (i == 3) ans++;
    }


    int start_index = 1;
    int end_index = P;

    while (1)
    {
        if (end_index == S)
            break;
        char next = DNA[end_index];
        char previous = DNA[start_index - 1];
        switch (next)
        {
            case 'A':
                current[0]++;
                break;
            case 'C':
                current[1]++;
                break;
            case 'G':
                current[2]++;
                break;
            case 'T':
                current[3]++;
                break;
        }
        switch (previous)
        {
            case 'A':
                current[0]--;
                break;
            case 'C':
                current[1]--;
                break;
            case 'G':
                current[2]--;
                break;
            case 'T':
                current[3]--;
                break;
        }
        for (int i = 0; i < 4; i++)
        {
            if (current[i] < condition[i])
                break;
            if (i == 3) ans++;
        }

        start_index++;
        end_index++;
    }

    cout << ans;
    return 0;
}