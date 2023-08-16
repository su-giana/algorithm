#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int> > houses(1000, vector<int>(3, 0));
vector<vector<int> > dp(1001, vector<int>(3, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int r, g, b;
        cin>>r>>g>>b;

        houses[i][0] = r;
        houses[i][1] = g;
        houses[i][2] = b;
    }

    for(int i = 1 ; i<=n ; i++)
    {
        dp[i][0] = houses[i-1][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = houses[i-1][1] + min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = houses[i-1][2] + min(dp[i-1][1], dp[i-1][0]);
    }

    cout<<min(min(dp[n][0], dp[n][1]), dp[n][2]);
}