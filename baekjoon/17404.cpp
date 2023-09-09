#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int> > houses(1000, vector<int>(3, 0));
vector<vector<vector<int> > > dp(1001, vector<vector<int> >(3, vector<int>(3, 987654321)));

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

        houses[i] = {r, g, b};
    }

    dp[1] = vector<vector<int> >(3, vector<int>(3, 987654321));
    dp[1][0][0] = houses[0][0]; dp[1][1][1] = houses[0][1]; dp[1][2][2] = houses[0][2];

    for(int i = 2 ; i<n ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            for(int k = 0 ; k<3 ; k++)
            {
                if(j==k)    continue;

                for(int h = 0 ; h<3 ; h++)
                {
                    dp[i][h][j] = min(dp[i][h][j], houses[i-1][j] + dp[i-1][h][k]);
                }
            }
        }
    }

    for(int i = 0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(i==j)    continue;

            for(int k = 0 ; k<3 ; k++)
            {
                if(j==k)    continue;

                dp[n][k][j] = min(dp[n-1][k][i] + houses[n-1][j], dp[n][k][j]);
            }
        }
    }

    int ans = 987654321;

    for(int i = 0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            ans = min(ans, dp[n][i][j]);
        }
    }

    cout<<ans;
}