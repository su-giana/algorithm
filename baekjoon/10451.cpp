#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int dfs(vector<vector<int> >& vertices, vector<bool>& visited, int vertex)
{
    if(visited[vertex])     return 1;
    visited[vertex] = true;

    int n = vertices[vertex].size();
    for(int i = 0 ; i<n ; i++)
    {
        if(dfs(vertices, visited, vertices[vertex][i]))
            return 1;
    }

    return 0;
}

int main()
{
    int t;
    cin>>t;

    for( ; t>0 ; t--)
    {
        int n;
        cin>>n;

        vector<vector<int> > vertices(n+1, vector<int>());
        for(int i = 1 ; i<=n ; i++)
        {
            int num;
            cin>>num;
            vertices[i].push_back(num);
        }

        int ans = 0;
        vector<bool> visited(n+1, false);
        for(int i = 1 ; i<=n ; i++)
        {
            if(!visited[i])
            {
                ans += dfs(vertices, visited, i);
            }
        }

        cout<<ans<<endl;
    }
}

