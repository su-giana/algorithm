#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> stairs(n, 0);
    vector<vector<int> > dp(n, vector<int>(2, 0));

    for(int i = 0 ; i<n ; i++)
    {
        int stair;
        cin>>stair;
        stairs[i] = stair;
    }

    if(n==1)    { cout<<stairs[0]; return 0;}
    
    dp[0][0] = stairs[0];
    dp[1][0] = stairs[1];
    dp[1][1] = stairs[1] + stairs[0];

    for(int i = 2 ; i<n ; i++)
    {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stairs[i];
        dp[i][1] = dp[i-1][0] + stairs[i];
    }

    cout<<max(dp[n-1][0], dp[n-1][1]);

    return 0;
}