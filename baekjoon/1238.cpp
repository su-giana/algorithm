#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, x;

vector<vector<pair<int, int> > > graph(1000, vector<pair<int, int> >());

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs(int start, int summit)
{
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> visited(n, INT_MAX);
    q.push(make_pair(0, start));
    visited[start] = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int weight = q.top().first;
        q.pop();

        int v_size = graph[cur].size();
        for(int i = 0 ; i<v_size ; i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            if(visited[next] > weight + cost)
            {
                visited[next] = weight + cost;
                q.push(make_pair(visited[next], next));
            }
        }
    }
    
    return visited[summit];
}

int main()
{
    init();

    cin>>n>>m>>x;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        graph[a-1].push_back(make_pair(b-1, c));
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        ans = max(ans, bfs(i, x-1) + bfs(x-1, i));
    }

    cout<<ans;
}