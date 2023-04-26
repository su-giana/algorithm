#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n+1, 1000001);

    nums[1] = 0;

    for(int i = 2 ; i<=n ; i++)
    {
        if(i%2==0)    nums[i] = min(nums[i], nums[i/2]+1);
        if(i%3==0)    nums[i] = min(nums[i], nums[i/3]+1);

        if(i%2==1)     nums[i] = min(nums[i], nums[(i-1)/2]+2);
        if(i%3==1)  nums[i] = min(nums[i], nums[(i-1)/3]+2);
        if(i%3==2)  nums[i] = min(nums[i], nums[(i-2)/3]+3);
    }

    cout<<nums[n];
}