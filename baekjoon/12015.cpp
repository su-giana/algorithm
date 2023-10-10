#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums(1000000, 0);
vector<int> lis;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int binarySearch(int now)
{
    int left = 0;
    int right = lis.size() - 1;

    while(left < right)
    {
        int mid = left + (right - left) / 2;

        if(lis[mid] >= now)  right = mid;
        else    left = mid+1;
    }

    return right;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    lis.push_back(nums[0]);

    for(int i = 1 ; i<n ; i++)
    {
        if(nums[i] > lis.back())
        {
            lis.push_back(nums[i]);
        }
        else if(nums[i] < lis.back())
        {
            int idx = binarySearch(nums[i]);
            lis[idx] = nums[i];
        }
    }

    cout<<lis.size();
}