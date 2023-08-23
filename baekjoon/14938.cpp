#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, r;
vector<vector<pair<int, int> > > graph(100, vector<pair<int, int> >());
vector<int> price(100, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> visited(n, INT_MAX);
    visited[start] = 0;
    q.push(make_pair(0, start));
    int ans = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int accumulated = q.top().first;
        q.pop();

        int g_size = graph[cur].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            if(visited[next] > accumulated+cost)
            {
                visited[next] = accumulated + cost;
                q.push(make_pair(accumulated + cost, next));
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(visited[i] <= m)
        {
            ans += price[i];
        }
    }

    return ans;
}

int main()
{
    init();

    cin>>n>>m>>r;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>price[i];
    }

    for(int i = 0 ; i<r ; i++)
    {
        int a, b, l;
        cin>>a>>b>>l;

        graph[a-1].push_back(make_pair(b-1, l));
        graph[b-1].push_back(make_pair(a-1, l));
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        ans = max(ans, bfs(i));
    }

    cout<<ans;
}