#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;

int v;
int m_max = 1;

void bfs(int index)
{
    queue<int> my_queue;
    my_queue.push(index);
    visited[index] = true;

    while (!my_queue.empty())
    {
        int now = my_queue.front();
        my_queue.pop();

        for (edge i: A[now])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                my_queue.push(i.first);
                m_distance[i.first] = m_distance[now] + i.second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v;

    A.resize(v + 1);
    m_distance = vector<int>(v + 1, 0);
    visited = vector<bool>(v + 1, false);

    for (int i = 0; i < v; i++)
    {
        int s;
        cin >> s;

        while (true)
        {
            int e, v;
            cin >> e;
            if (e == -1)
                break;
            cin >> v;
            A[s].push_back(edge(e, v));
        }
    }
    
    bfs(1);

    for (int i = 2; i <= v; i++)
    {
        if (m_distance[m_max] < m_distance[i])
            m_max = i;
    }

    fill(m_distance.begin(), m_distance.end(), 0);
    fill(visited.begin(), visited.end(), false);

    bfs(m_max);
    sort(m_distance.begin(), m_distance.end());
    
    cout << m_distance[v] << "\n";

    return 0;
}