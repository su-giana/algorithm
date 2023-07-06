#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph(15, vector<int>(15, 0));
vector<vector<vector<bool> > > map(15, vector<vector<bool> >( (1<<15), vector<bool>(10, false)));
int n;
int cnt = 0;

void dfs(int cur, int price, int visited)
{
    if(map[cur][visited][price])    return;
    map[cur][visited][price] = true;
    cnt = max(cnt, __builtin_popcount(visited));

    for(int i = 0 ; i<n ; i++)
    {
        if((visited & (1<<i)) || (price > graph[cur][i]))    continue;
        dfs(i, graph[cur][i], (visited | (1<<i)));
    }
}

int main()
{
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<n ; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    dfs(0, 0, (1<<0));

    cout<<cnt;
}