#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> glasses(n+1, 0);
    vector<int> dp(n+1, 0);

    for(int i = 1 ; i<=n ; i++)
    {
        int glass;
        cin>>glass;

        glasses[i] = glass;
    }

    dp[1] = glasses[1];
    dp[2] = glasses[1] + glasses[2];
    for(int i = 3 ; i<=n ; i++)
    {
        dp[i] = max(dp[i-1], max(dp[i-3] + glasses[i-1] + glasses[i], dp[i-2] + glasses[i]));
    }

    cout<<dp[n];

    return 0;
}