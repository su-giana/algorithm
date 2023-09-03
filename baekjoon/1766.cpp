#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > graph(32000, vector<int>());
vector<bool> visited(32000, false);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cur)
{
    int v_size = graph[cur].size();

    sort(graph[cur].begin(), graph[cur].end());

    for(int i = 0 ; i<v_size ; i++)
    {
        int next = graph[cur][i];
        if(!visited[next])
        {
            visited[next] = true;
            dfs(next);
        }
    }

    cout<<cur+1<<" ";
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        graph[b-1].push_back(a-1);
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
}