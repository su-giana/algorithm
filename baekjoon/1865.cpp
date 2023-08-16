#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, w;

vector<vector<int> > graph;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool bellmanFord(int start)
{
    vector<long long> dis(500, INT_MAX);

    for(int i = 1 ; i<n ; i++)
    {
        int g_size = graph.size();
        for(int j = 0 ; j<g_size ; j++)
        {
            int from = graph[j][0];
            int to = graph[j][1];
            int cost = graph[j][2];

            if(dis[to] > dis[from] + cost)
            {
                dis[to] = dis[from] + cost;
            }
        }
    }

    int g_size = graph.size();
    for(int i = 0 ; i<g_size ; i++)
    {
        int from = graph[i][0];
        int to = graph[i][1];
        int cost = graph[i][2];

        if(dis[from] == INT_MAX)    continue;

        if(dis[to] > dis[from] + cost)
            return true;
    }

    return false;
}

int main()
{
    init();

    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>w;

        while(m--)
        {
            int s, e, t;
            cin>>s>>e>>t;

            graph.push_back({s-1, e-1, t});
            graph.push_back({e-1, s-1, t});
        }

        while(w--)
        {
            int s, e, t;
            cin>>s>>e>>t;
            graph.push_back({s-1, e-1, t*-1});
        }

        if(bellmanFord(0))
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }

        graph.clear();
    }
}