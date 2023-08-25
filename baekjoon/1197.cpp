#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<vector<pair<int, int> > > tree(10000, vector<pair<int, int> >());
vector<int> root(10000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int prim()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<bool> visited(v, false);

    q.push(make_pair(0, 0));
    visited[0] = true;

    int a_size = tree[0].size();
    for(int i = 0 ; i<a_size ; i++)
    {
        q.push(make_pair(tree[0][i].second, tree[0][i].first));
    }

    int ans = 0;

    while(!q.empty())
    {
        int cur = q.top().second;
        int acc = q.top().first;
        q.pop();

        if(!visited[cur])
        {
            visited[cur] = true;
            ans += acc;

            a_size = tree[cur].size();
            for(int i = 0 ; i<a_size ; i++)
            {
                int next = tree[cur][i].first;
                int cost = tree[cur][i].second;

                q.push(make_pair(cost, next));                
            }
        }
    }
    
    return ans;
}

int main()
{
    init();

    cin>>v>>e;

    for(int i = 0 ; i<e ; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        tree[a-1].push_back(make_pair(b-1, c));
        tree[b-1].push_back(make_pair(a-1, c));
    }

    cout<<prim();
}