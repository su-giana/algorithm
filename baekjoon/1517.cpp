#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getSwap(vector<long long>& nums, int left, int right)
{
    if(left >= right)   return 0;
    
    int n = nums.size();

    int lastMaxIndex = right;
    for(int i = right-1 ; i>=left ; i--)
    {
        if(nums[lastMaxIndex] < nums[i])
        {
            lastMaxIndex = i;
        }
    }

    long long ans = right - lastMaxIndex;

    if(right != lastMaxIndex)
    {
        long long temp = nums[lastMaxIndex];
        nums.erase(nums.begin() + lastMaxIndex);
        nums.insert(nums.begin() + right, temp);
    }

    ans += getSwap(nums, left, lastMaxIndex-1);
    ans += getSwap(nums, lastMaxIndex, right-1);
    ans += getSwap(nums, left, right-1);
    return ans;
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<long long> nums(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        long long num;
        cin>>num;
        nums[i] = num;
    }

    cout<<getSwap(nums, 0, n-1);
}