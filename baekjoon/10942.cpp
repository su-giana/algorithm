#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> nums(2000, 0);
vector<vector<int> > dp(2000, vector<int>(2000, 1));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)  cin>>nums[i];

    for(int i = 1 ; i<n ; i++)
    {
        for(int j = 0 ; j + i < n ; j++)
        {
            dp[j][i+j] = dp[j+1][i+j-1] && (nums[j] == nums[i+j]);
        }
    }

    cin>>m;

    while(m--)
    {
        int a, b;
        cin>>a>>b;

        cout<<dp[a-1][b-1]<<'\n';
    }
}