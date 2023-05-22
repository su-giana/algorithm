#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;

    vector<vector<long long> > dp(k, vector<long long>(n+1, 1));

    for(int i = 1 ; i<k ; i++)
    {
        for(int j =1 ; j<=n ; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }

    cout<<dp[k-1][n];
}