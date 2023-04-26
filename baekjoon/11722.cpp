#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n, 0);
    vector<int> dp(n, 1);

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }

    for(int i = n-1 ; i>=0 ; i--)
    {
        int temp = arr[i];
        for(int j = i-1 ; j>=0 ; j--)
        {
            if(temp<arr[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    cout<<*max_element(dp.begin(), dp.end());
}