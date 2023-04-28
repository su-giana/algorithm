#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void dfs(vector<vector<int> >& vertices, vector<bool>& visited, int vertex)
{
    if(visited[vertex]) return;
    visited[vertex] = true;
    cout<<vertex<<" ";

    int n = vertices[vertex].size();
    for(int i = 0 ; i<n ; i++)
    {
        dfs(vertices, visited, vertices[vertex][i]);
    }
}

void bfs(vector<vector<int> >& vertices, int vertex)
{
    int n = vertices.size();
    vector<bool> visited(n, false);
    queue<int> que;

    que.push(vertex);
    visited[vertex] = true;
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout<<cur<<" ";

        int n = vertices[cur].size();
        for(int i = 0 ; i<n ; i++)
        {
            int next = vertices[cur][i];
            if(!visited[next])
            {
                que.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    init();

    int n, m ,v;
    cin>>n>>m>>v;

    vector<vector<int> > vertices(n+1, vector<int>());
    for(int i = 0 ; i<m ; i++)
    {
        int in, out;
        cin>>in>>out;

        vertices[in].push_back(out);
        vertices[out].push_back(in);
    }

    for(int i = 1 ; i<=n ; i++)
    {
        sort(vertices[i].begin(), vertices[i].end());
    }

    vector<bool> visited(n+1, false);
    dfs(vertices, visited, v);
    cout<<endl;
    bfs(vertices, v);
}