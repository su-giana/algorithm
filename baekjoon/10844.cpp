#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<long long> > dp(n+1, vector<long long>(10, 1));
    dp[1][0] = 0;


    for(int i = 2 ; i<=n ; i++)
    {
        for(int j = 0 ; j<10 ; j++)
        {
            if(!j)           dp[i][0] = dp[i-1][1];
            else if(j==9)    dp[i][9] = dp[i-1][8];
            else             dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]);
            dp[i][j] %= 1000000000;
        }
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
        ans =  (ans + dp[n][i]) % 1000000000;
    cout<<ans;
}