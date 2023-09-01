#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

int n, m, target;
vector<vector<int> > dis;
vector<int> root(100000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int find(int cur)
{
    if(cur == root[cur])    return cur;
    return find(root[cur]);
}

void merge(int a, int b)
{
    int left = find(a);
    int right = find(b);

    if(left == target)
    {
        root[right] = left;
    }
    else if(right == target)
    {
        root[left] = right;
    }

    root[min(left, right)] = max(left, right);
}

void bfs()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    vector<long long> visited(100000, LLONG_MAX);
    q.push(make_pair(0, 0));
    visited[0] = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int acc = q.top().first;
        q.pop();

        for(int i = 0 ; i<m ; i++)
        {
            if(dis[i][1] != cur)    continue;
            int next = dis[i][2];
            int cost = dis[i][0];

            if(visited[next] > acc + cost)
            {
                root[next] = cur;
                visited[next] = acc + cost;
                q.push(make_pair(visited[next], next));
            }
        }
    }

    target = max_element(visited.begin(), visited.end()) - visited.begin() - 1;
}

long long prim()
{
    sort(dis.begin(), dis.end());
    long long ans = 0;

    for(int i = 0 ; i<m ; i++)
    {
        int a = find(dis[i][1]);
        int b = find(dis[i][2]);
        int cost = dis[i][0];

        if(a==0 && b==target)  continue;
        if(a == target && b== 0)   continue;
        if(a == b)   continue;
        ans += cost;
        merge(a, b);
    }

    return ans;
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)  root[i] = i;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        dis.push_back({c, a-1, b-1});
    }

    bfs();
    cout<<prim();
}