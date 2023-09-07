#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int n;
vector<vector<int> > map(16, vector<int>(16, 0));
vector<vector<int> > dp(16, vector<int>(1<<16, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dfs(int cur, int visited)
{
    if(visited == (1<<n)-1)
    {
        if(map[cur][0] > 0)
        {
            return map[cur][0];
        }

        return 987654321;
    }

    if(dp[cur][visited] != 0)   return dp[cur][visited];

    dp[cur][visited] = 987654321;

    for(int i = 0 ; i<n ; i++)
    {
        if(map[cur][i] == 0)    continue;

        if(visited & (1<<i))    continue;

        dp[cur][visited] = min(dp[cur][visited], map[cur][i] + dfs(i, visited | (1<<i)));
    }

    return dp[cur][visited];
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map[i][j];
        }
    }

    cout<<dfs(0, 1);
}