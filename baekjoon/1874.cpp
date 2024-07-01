#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> ar;
stack<int> st;
int dish = 1;
string ans = "";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        int target = ar[i];
        if (st.size() && target == st.top())
        {
            st.pop();
            ans += "-\n";
            continue;
        }
        else if (st.size() && st.top() > target)
        {
            cout << "NO\n";
            ans = "";
            break;
        }
        if (!st.size())
        {
            st.push(dish++);
            ans += "+\n";
        }
        while (st.size() && st.top() != target)
        {
            st.push(dish++);
            ans += "+\n";
        }
        if (st.size())
            st.pop();
        ans += "-\n";
    }

    cout << ans;

    return 0;
}