#include <iostream>
#include <vector>

using namespace std;

string s1, s2;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>s1>>s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=m ; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m];
}