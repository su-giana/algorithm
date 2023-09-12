#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<long long> dp(10001, 0);
vector<int> cost(100, 0);
vector<int> memory(100, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>m;
    int c_sum = 0;

    for(int i = 0 ; i<n ; i++)  cin>>memory[i];
    for(int i = 0 ; i<n ; i++)
    {
        cin>>cost[i];
        c_sum += cost[i];
    }

    dp[0] = 0;

    for(int i = 0 ; i<n ; i++)
    {
        vector<long long> n_dp = dp;
        
        for(int j = 0 ; j<=c_sum ; j++)
        {
            if(j < cost[i])   continue;
            n_dp[j] = max(n_dp[j], dp[j - cost[i]] + memory[i]);
        }
        
        dp = n_dp;
    }

    for(int i = 0 ; i<=c_sum ; i++)
    {
        if(dp[i] >= m)
        {
            cout<<i;
            break;
        }
    }
}