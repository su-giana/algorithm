#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > graph(32000, vector<int>());
vector<bool> visited(32000, false);
vector<int> root(320000, 0);
vector<vector<int> > ans;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void topology_sort(int now)
{
    vector<int> tmp;
    priority_queue<int, vector<int>, greater<int> > q;
    visited[now] = true;
    q.push(now);

    while(!q.empty())
    {
        int cur = q.top();
        q.pop();

        tmp.push_back(cur);

        int v_size = graph[cur].size();
        sort(graph[cur].begin(), graph[cur].end());
        for(int i = 0 ; i<v_size ; i++)
        {
            int next = graph[cur][i];
            if(!visited[next])
            {
                root[next]--;
                if(root[next] == 0)
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        graph[cur].clear();
    }

    ans.push_back(tmp);
}

void solve_()
{
    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i] && root[i] == 0)
        {
            visited[i] = true;
            topology_sort(i);
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    int a_size = ans.size();
    for(int i = 0 ; i<a_size ; i++)
    {
        int s_size = ans[i].size();
        for(int j = 0 ; j<s_size ; j++)
        {
            cout<<ans[i][j]+1<<" ";
        }
    }
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        root[b-1]++;

        graph[a-1].push_back(b-1);
    }

    solve_();
}