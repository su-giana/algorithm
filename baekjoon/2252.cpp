#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> nums;
vector<vector<int> > graph(32000, vector<int>());
vector<int> indegree;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs()
{
    queue<int> q;
    vector<bool> visited(n, false);

    for(int i = 0 ; i<n ; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout<<cur+1<<" ";

        int g_size = graph[cur].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[cur][i];

            indegree[next]--;

            if(!visited[next] && indegree[next] == 0)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    init();

    cin>>n>>m;

    nums.resize(n, 0);  indegree.resize(n, 0);

    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        indegree[b-1]++;
    }

    bfs();
}