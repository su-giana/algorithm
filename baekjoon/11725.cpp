#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs(vector<vector<int> >& graph, vector<int>& parents)
{
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        int m = graph[cur].size();
        for(int i = 0 ; i<m ; i++)
        {
            int next = graph[cur][i];
            if(!visited[next])
            {
                parents[next] = cur;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<int> > graph(n+1, vector<int>());
    
    for(int i = 0 ; i<n-1 ; i++)
    {
        int in, out;
        cin>>in>>out;

        graph[in].push_back(out);
        graph[out].push_back(in);
    }

    vector<int> parents(n+1, 0);
    for(int i = 1 ; i<=n ; i++)
    {
        parents[i] = i;
    }

    bfs(graph, parents);

    for(int i = 2 ; i<=n ; i++)
    {
        cout<<parents[i]<<'\n';
    }
}