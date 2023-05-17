#include <iostream>
#include <vector>

using namespace std;

long long getSum(vector<int>& ex)
{
    long long sum = 0;
    int n = ex.size();

    for(int i = 0 ; i<n-1 ; i++)
    {
        sum += abs(ex[i] - ex[i+1]);
    }

    return sum;
}

long long getMaxSum(vector<int>& nums, vector<int> ex)
{
    if(nums.size() == ex.size())
    {
        return getSum(ex);
    }

    int n = nums.size();
    int index = ex.size();

    long long maxSum = 0;
    for(int i = 0 ; i<=index ; i++)
    {
        vector<int> temp(ex.begin(), ex.end());
        temp.insert(temp.begin() + i, nums[index]);
        maxSum = max(maxSum, getMaxSum(nums, temp));
    }

    return maxSum;
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    cout<<getMaxSum(nums, vector<int>());
}