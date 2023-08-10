#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> nums;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int bs(int target)
{
    int left = 0 ; 
    int right = nums.size() - 1;

    while(left<=right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
        {
            return 1;
        }
        else if(nums[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return 0;
}

int main()
{
    init();

    cin>>n;
    nums.resize(n, 0);

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());

    cin>>m;
    for(int i = 0 ; i<m ; i++)
    {
        int target;
        cin>>target;

        cout<<bs(target)<<'\n';
    }

}