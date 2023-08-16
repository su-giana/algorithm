#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, e;
vector<vector<pair<int, int> > > graph(800, vector<pair<int, int> >());

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs(int start, int summit)
{
    if(start == summit) return 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> visited(n, INT_MAX);
    visited[start] = 0;
    q.push(make_pair(0, start));

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

    return visited[summit] == INT_MAX ? -1 : visited[summit];
}

int main()
{
    init();
    cin>>n>>e;

    for(int i = 0 ; i<e ; i++)
    {
        int x, y, c;
        cin>>x>>y>>c;

        graph[x-1].push_back(make_pair(y-1, c));
        graph[y-1].push_back(make_pair(x-1, c));
    }

    int a, b;
    cin>>a>>b;

    int startToA = bfs(0, a-1);
    int aToB = bfs(a-1, b-1);
    int bToEnd = bfs(b-1, n-1);

    int ab = startToA>=0 && aToB>=0 && bToEnd>=0 ? startToA + aToB + bToEnd : -1;

    int startToB = bfs(0, b-1);
    int bToA = bfs(b-1, a-1);
    int aToEnd = bfs(a-1, n-1);

    int ba = startToB>=0 && bToA>=0 && aToEnd>=0 ? startToB + bToA + aToEnd : -1;

    if(ab == -1 && ba==-1)  cout<<-1;
    else if(ab!=-1 && ba!=-1)   cout<<min(ab, ba);
    else    cout<<max(ab, ba);
}