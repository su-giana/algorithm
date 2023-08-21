#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int> > products(100, make_pair(0, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>k;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>products[i].first;
        cin>>products[i].second;
    }

    vector<vector<long long> > dp(n+1, vector<long long>(k+1, 0));

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=k ; j++)
        {
            dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
            if(j>=products[i-1].first)
                dp[i][j] = max(dp[i][j], dp[i-1][j - products[i-1].first] + products[i-1].second);
        }
    }

    cout<<dp[n][k];
}