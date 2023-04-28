#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<vector<int> >& vertices, vector<bool>& visited, int vertex)
{
    if(visited[vertex]) return;
    visited[vertex] = true;

    int n = vertices[vertex].size();
    for(int i = 0 ; i<n ; i++)
    {
        int cur = vertices[vertex][i];
        dfs(vertices, visited, cur);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int> > vertices(n+1, vector<int>());
    for(int i = 0 ; i<m ; i++)
    {
        int in, out;
        cin>>in>>out;
        vertices[in].push_back(out);
        vertices[out].push_back(in);
    }

    vector<bool> visited(n+1, false);
    int ans = 0;
    for(int i = 1 ; i<=n ; i++)
    {
        if(!visited[i])
        {
            dfs(vertices, visited, i);
            ans++;
        }
    }

    cout<<ans;
}