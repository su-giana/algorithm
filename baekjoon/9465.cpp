#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int k = 0 ; k<t ; k++)
    {
        int n;
        cin>>n;

        vector<vector<int> > dp(2, vector<int>(n, 0));

        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 0 ; j<n ; j++)
                { cin>>dp[i][j]; }

        }

        

        for(int i = 1 ; i<n ; i++)
        {
            if(i==1)
            {
                dp[0][1] += dp[1][0];
                dp[1][1] += dp[0][0];
                continue;
            }

            int twoL = max(dp[0][i-2], dp[1][i-2]);
            dp[0][i] += max(dp[1][i-1], twoL);
            dp[1][i] += max(dp[0][i-1], twoL);
        }

        cout<<max(dp[0][n-1], dp[1][n-1])<<endl;
    }
}