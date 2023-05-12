#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums;
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    vector<int> dp(n, 0);

    long long ans = 0;
    for(int i = 1 ; i<n ; i++)
    {
        for(int j = i-1 ; j>=0 ; j--)
        {
            int standard = min(nums[i], nums[j]);

            dp[j] = max(dp[j], dp[j+1]);

            if(dp[j] < standard)
            {
                ans += (i - j + 1);
            }
        }
        dp[i-1] = nums[i];
    }

    cout<<ans;
}