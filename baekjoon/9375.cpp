#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int p = 0; p < t; p++)
    {
        unordered_map<string, int> m;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string c_name, c_type;
            cin >> c_name >> c_type;
            m[c_type]++;
        }
        
        int c = 1;

        for (const auto& i: m)
        {
            c *= (i.second + 1);
        }

        cout << c - 1 << '\n';
    }

}