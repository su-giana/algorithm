#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<vector<long long> > > dp(500, vector<vector<long long> >(500, vector<long long>(3, (1ll<<62)-1)));

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

    for(int i= 0 ; i<n ; i++)
    {
        cin>>dp[i][i][0];
        cin>>dp[i][i][1];
        dp[i][i][2] = 0;
    }

    for(int i = 1 ; i<n ; i++)
    {
        for(int j = 0 ; j+i<n ; j++)
        {
            int l_start = j;
            int l_end = j+i;

            for(int k = l_start ; k<l_end ; k++)
            {
                int dn = dp[l_start][k][0];
                int dm = dp[l_start][k][1];
                int dk = dp[k+1][l_end][1];
                if(dp[l_start][l_end][2] > dp[l_start][k][2] + dp[k+1][l_end][2] + dn * dm * dk)
                {
                    dp[l_start][l_end][0] = dn;
                    dp[l_start][l_end][1] = dk;
                    dp[l_start][l_end][2] = dp[l_start][k][2] + dp[k+1][l_end][2] + dn * dm * dk;
                }
            }
        }
    }

    cout<<dp[0][n-1][2];
}
