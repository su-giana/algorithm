#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > graph(1000, vector<pair<int, int> >());
int start;
int summit;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> dist(1000, INT_MAX);
    dist[start-1] = 0;
    q.push(make_pair(0, start-1));

    while(!q.empty())
    {
        int cur = q.top().second;
        int weight = q.top().first;
        q.pop();

        if(weight > dist[cur])   continue;

        int g_size = graph[cur].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            if(dist[next] > weight + cost)
            {
                dist[next] = weight + cost;
                q.push(make_pair(dist[next], next));
            }
        }
    }

    return dist[summit-1];
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int s, e, t;
        cin>>s>>e>>t;

        graph[s-1].push_back(make_pair(e-1, t));
    }

    cin>>start>>summit;
    cout<<bfs();
}