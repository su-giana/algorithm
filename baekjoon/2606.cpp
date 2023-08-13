#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > graph(100, vector<int>(100, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    int cnt = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i<n ; i++)
        {
            if(graph[cur][i] && !visited[i])
            {
                cnt++;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return cnt;
}

int main()
{
    init();

    cin>>n>>m;

    while(m--)
    {
        int x, y;
        cin>>x>>y;
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

    cout<<bfs();
}