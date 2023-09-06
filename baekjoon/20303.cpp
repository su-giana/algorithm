#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<vector<int> > graph(30000, vector<int>());
vector<int> candies(30000, 0);
vector<bool> visited(30000, false);
vector<pair<int, long long> > groups;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs(int cur)
{
    queue<int> q;
    visited[cur] = true;
    q.push(cur);
    int cnt = 0;
    long long total = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        cnt++;
        total += candies[now];

        int g_size = graph[now].size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph[now][i];
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    groups.push_back(make_pair(cnt, total));
}

int main()
{
    init();

    cin>>n>>m>>k;

    for(int i = 0 ; i<n ; i++)  cin>>candies[i];

    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }

    n = groups.size();

    vector<long long> dp(k, 0);

    for(int i = 1 ; i<=n ; i++)
    {
        int weight = groups[i-1].first;
        int cost = groups[i-1].second;

        vector<long long> tmp = dp;

        for(long long j = 1 ; j<k ; j++)
        {
            if(j-weight>=0)
            {
                tmp[j] = max(tmp[j], max(tmp[j-1], dp[j-weight] + cost));
            }
            else
            {
                tmp[j] = max(tmp[j], tmp[j-1]);
            }
        }

        dp = tmp;
    }

    cout<<dp[k-1];
}