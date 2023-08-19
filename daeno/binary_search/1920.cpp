#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> nums;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int binary_search(int val)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(val == nums[mid])
        {
            return 1;
        }
        else if(val < nums[mid])
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    
    return 0;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int m;
    cin>>m;
    while(m--)
    {
        int val;
        cin>>val;
        cout<<binary_search(val)<<'\n';
    }
}