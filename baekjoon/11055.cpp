#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    vector<int> dp(n, 1);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;

        arr.push_back(num);
        dp[i] = num;
    }

    for(int i = 0 ; i<n ; i++)
    {
        int temp = arr[i];
        for(int j = i+1 ; j<n ; j++)
        {
            if(arr[j]>temp)
            {
                dp[j] = max(dp[j], dp[i]+arr[j]);
            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());

    cout<<ans;
}