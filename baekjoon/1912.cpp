#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    vector<long long> dp(n ,0);

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }

    dp[0] = arr[0];
    for(int i = 1 ; i<n ; i++)
    {
        dp[i] = arr[i];
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
    }

    cout<<*max_element(dp.begin(), dp.end());

}