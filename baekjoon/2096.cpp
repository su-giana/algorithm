#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

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

    vector<pair<int, int> > dp(3, make_pair(0, 0));
    vector<int> nums(3, 0);

    for(int i = 0 ; i<n ; i++)
    {
        vector<pair<int, int> > cur(3, make_pair(0, INT_MAX));
        for(int j = 0 ; j<3 ; j++)
        {
            cin>>nums[j];
        }

        for(int j = 0 ; j<3 ; j++)
        {
            for(int k = j-1 ; k<=j+1 ; k++)
            {
                if(k<0 || k>2)  continue;

                cur[j].first = max(cur[j].first, dp[k].first + nums[j]);
                cur[j].second = min(cur[j].second, dp[k].second + nums[j]);
            }
        }
        dp = cur;
    }

    pair<int, int> ans = make_pair(0, INT_MAX);
    for(int i = 0 ; i<3 ; i++)
    {
        ans.first = max(ans.first, dp[i].first);
        ans.second = min(ans.second, dp[i].second);
    }

    cout<<ans.first<<" "<<ans.second;
}