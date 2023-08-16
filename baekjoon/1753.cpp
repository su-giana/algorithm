#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int v, e, k;
vector<vector<pair<int, int> > > graph(20000, vector<pair<int, int> > ());

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> visited(20000, INT_MAX);
    q.push(make_pair(0, k-1));
    visited[k-1] = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int weight = q.top().first;
        q.pop();

        int g_size = graph[cur].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            if(visited[next] > cost + weight)
            {
                visited[next] = cost + weight;
                q.push(make_pair(visited[next], next));
            }
        }
    }

    for(int i = 0 ; i<v ; i++)
    {
        string val = visited[i] == INT_MAX ? "INF" : to_string(visited[i]);
        cout<<val<<'\n';
    }
}

int main()
{
    init();

    cin>>v>>e>>k;

    for(int i = 0 ; i<e ; i++)
    {
        int x, y, c;
        cin>>x>>y>>c;

        graph[x-1].push_back(make_pair(y-1, c));
    }

    bfs();
}