#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> cards(n+1, 0);
    vector<long long> dp(n+1, 0);

    for(int i = 1 ; i<=n ; i++)
    {
        int card;
        cin>>card;
        cards[i] = card;
    }

    for(int i = 1 ; i<=n ; i++)
    {
        dp[i] = dp[i-1] + cards[1];
    }

    for(int i = 2 ; i<=n ; i++)
    {
        for(int j = i ; j<=n ; j++)
        {
            dp[j] = max(dp[j], dp[j-i] + cards[i]);
        }
    }

    cout<<dp[n];
}