#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long> dp(90, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2 ; i<90 ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n-1];

    return 0;
}