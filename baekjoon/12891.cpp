#include <iostream>

using namespace std;

int S, P;
string DNA;
int condition[4] = {0};
// A, C, G, T
int cnt = 0;

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

    int start_idx = 0;
    int end_idx = start_idx + P - 1;

    int A, C, G, T;
    A = C = G = T = 0;

    for (int i = 0; i < P; i++)
    {
        if (DNA[i] == 'A') A++;
        else if (DNA[i] == 'C') C++;
        else if (DNA[i] == 'G') G++;
        else T++;
    }

    while (1)
    {
        if (A >= condition[0] && C >= condition[1] && G >= condition[2] && T >= condition[3])
        {
            cnt++;
        }

        if (DNA[start_idx] == 'A') A--;
        else if (DNA[start_idx] == 'C') C--;
        else if (DNA[start_idx] == 'G') G--;
        else T--;

        if (DNA[end_idx + 1] == 'A') A++;
        else if (DNA[end_idx + 1] == 'C') C++;
        else if (DNA[end_idx + 1] == 'G') G++;
        else T++;

        start_idx++;
        if (++end_idx == S) 
            break;
    }

    cout << cnt << '\n';
    return 0;
}