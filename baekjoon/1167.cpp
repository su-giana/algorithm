#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

// first is biggest, second is biggest + 2nd biggest
pair<long long, long long> dfs(vector<vector<pair<int, int> > >& graph, vector<bool>& visited, int cur)
{
    int v = graph.size();
    visited[cur] = true;
    

    int n = graph[cur].size();
    priority_queue<long long> q1;
    priority_queue<long long> q2;
    for(int i = 0 ; i<n ; i++)
    {
        int next = graph[cur][i].first;
        if(!visited[next])
        {
            pair<long long, long long> temp = dfs(graph, visited, next);
            q1.push(temp.first + graph[cur][i].second);
            q2.push(temp.second);
        }
    }


    if(q1.empty())   return make_pair(0, 0);
    if(q1.size()==1) return make_pair(q1.top(), q2.top());
    long long biggest = q1.top();
    q1.pop();
    return make_pair(biggest, max(biggest + q1.top(), q2.top()));
}

int main()
{
    init();

    int v;
    cin>>v;
    vector<vector<pair<int, int> > > graph(v+1, vector<pair<int, int> >());

    for(int i = 0 ; i<v ; i++)
    {
        int x;
        cin>>x;

        while(true)
        {
            int y;
            cin>>y;
            if(y==-1)   break;

            int w;
            cin>>w;
            graph[x].push_back(make_pair(y, w));
        }
    }

    long long maxSum = 0;
    vector<bool> visited(v+1, false);
    for(int i = 1 ; i<=v ; i++)
    {
        if(visited[i] == false)
        {
            pair<long long, long long> ans = dfs(graph, visited, i);
            maxSum = max({maxSum, ans.first, ans.second});
        }
    }

    cout<<maxSum;
}