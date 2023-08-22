#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > graph(1000, vector<pair<int, int> >());
int start, summit;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dijstra()
{
    if(start == summit)
    {
        cout<<0<<'\n'<<1<<'\n'<<start;
        return;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> root(n, -1);
    vector<int> cost(n, INT_MAX);
    for(int i = 0 ; i<n ; i++)  root[i] = i;

    q.push(make_pair(0, start-1));
    cost[start-1] = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int stackedCost = q.top().first;
        q.pop();

        if(stackedCost > cost[cur]) continue;

        int g_size = graph[cur].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;

            if(cost[next] > stackedCost + nextCost)
            {
                cost[next] = stackedCost + nextCost;
                q.push(make_pair(cost[next], next));
                root[next] = cur;
            }
        }
    }

    cout<<cost[summit-1]<<'\n';
    vector<int> path;
    int cur = summit-1;
    path.push_back(cur);
    while(cur != start-1)
    {
        path.push_back(root[cur]);
        cur = root[cur];
    }

    int p_size = path.size();
    cout<<p_size<<'\n';
    for(int i = p_size-1 ; i>=0 ; i--)
    {
        cout<<path[i]+1<<' ';
    }
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int s, e, c;
        cin>>s>>e>>c;

        graph[s-1].push_back(make_pair(e-1, c));
    }

    cin>>start>>summit;

    dijstra();
}