#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> dp(10, 0);

    for(int i = 0 ; i<10 ; i++)
    {
        dp[i] = i+1;
    }

    while(n>1)
    {
        for(int i = 1 ; i<10 ; i++)
            dp[i] = (dp[i-1] + dp[i]) % 10007;
        
        n--;
    }

    cout<<dp[9];
}