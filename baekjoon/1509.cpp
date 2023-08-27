#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string s;

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

    vector<vector<bool> > dp(2500, vector<bool>(2500, true));

    for(int i = 0 ; i<n-1 ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            dp[n+i-j][j] = dp[n+i-j-1][j-1] && (s[n+i-j] == s[n-j-1]);
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
}