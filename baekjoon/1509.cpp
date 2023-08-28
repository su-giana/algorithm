#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

string s;
vector<vector<bool> > dp(2500, vector<bool>(2500, true));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>s;

    int n = s.length();

    for(int i = 0 ; i<n-1 ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            dp[n+i-j][j] = dp[n+i-j-1][j-1] && (s[n+i-j] == s[n-j-1]);
        }
    }

    vector<int> ans(2501, 22345678);

    ans[0] = 0;
    ans[1] = 1;

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = i ; j<=n ; j++)
        {
            if(dp[j-1][n-i])
            {
                ans[j] = min(ans[j], ans[i-1] + 1);
            }
        }
    }

    cout<<ans[n];
}