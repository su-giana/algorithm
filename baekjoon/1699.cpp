#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n+1, 100001);

    nums[0] = 0;
    for(int i = 1 ; i*i <= n ; i++)
    {
        nums[i*i] = 1;
    }

    for(int i = 2 ; i<=n ; i++)
    {
        nums[i] = min(nums[i], nums[i-1] + 1);

        for(int j = 1 ; j*j <= i ; j++)
        {
            int temp = i / (j*j);
            temp += nums[i % (j*j)];

            nums[i] = min(nums[i], temp);
        }
    }

    cout<<nums[n];
}