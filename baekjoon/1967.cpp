#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<vector<pair<int, int> > >& graph, vector<int>& width, vector<bool>& visited, int x)
{
    if(visited[x])  return 0;

    int n = graph[x].size();
    for(int i = 0 ; i<n ; i++)
    {
        int next = graph[x][i].first;
        int weight = graph[x][i].second;

    }
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();
    int n;
    cin>>n;

    vector<int> width(n+1, -1);
    vector<bool> visited(n+1, false);
    vector<vector<pair<int, int> > > graph(n+1, vector<pair<int, int> >());
    for(int i = 0 ; i<n-1 ; i++)
    {
        int in, out, weight;
        cin>>in>>out>>weight;

        graph[in].push_back(make_pair(out, weight));
    }

    for(int i = 1 ; i<=n ; i++)
    {
        if(width[i] == -1)
        {
            width[i] = dfs(graph, width, visited, i);
        }
    }

    cout<<*max_element(width.begin(), width.end());
}