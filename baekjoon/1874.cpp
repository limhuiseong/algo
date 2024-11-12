#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> my_stack;
vector<int> numbers;
vector<int> arr;
string ans;
bool isNo = false;

void push(int a)
{   
    ans += "+\n";
    my_stack.push_back(a);
}

int pop()
{
    ans += "-\n";
    int tmp = my_stack.back();
    my_stack.pop_back();

    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = n; i >= 1 ; i--)
    {   
        numbers.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    push(numbers.back());
    numbers.pop_back();

    for (int i = 0; i < n; i++)
    {
        int target = arr[i];
        if (my_stack.back() > target)
        {
            isNo = true;
            cout << "NO\n";
            break;
        }
        while (target != my_stack.back())
        {
            if (!numbers.empty())
            {
                push(numbers.back());
                numbers.pop_back();
            }
            else
            {
                isNo = true;
                cout << "NO\n";
                break;
            }
        }
        pop();
    }

    if (!isNo)
        cout << ans;
    
}