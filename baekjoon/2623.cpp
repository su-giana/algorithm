#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > graph(1000, vector<int>());
vector<int> vertice(1000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<int> topology_sort()
{
    queue<int> q;
    vector<int> ans;

    for(int i = 0 ; i<n ; i++)
    {
        if(vertice[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        ans.insert(ans.begin(), cur);

        int g_size = graph[cur].size();
        for(int i = 0 ; i < g_size ; i++)
        {
            int next = graph[cur][i];

            vertice[next]--;

            if(vertice[next] == 0)  q.push(next);
        }
    }

    if(ans.size() == n) return ans;
    else                return {-1};
}

int main()
{
    init();

    cin>>n>>m;

    while(m--)
    {
        int t;
        cin>>t;

        if(t==0)    continue;
        else    t-=1;

        int prev;
        cin>>prev;

        while(t--)
        {
            int next;
            cin>>next; 

            graph[next-1].push_back(prev-1);
            vertice[prev-1]++;
            prev = next;
        }
    }

    vector<int> ans = topology_sort();

    int a_size = ans.size();
    for(int i = 0 ; i<a_size ; i++) cout<<ans[i]+1<<'\n';
}