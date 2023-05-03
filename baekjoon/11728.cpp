#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int n, m;
    cin>>n>>m;

    vector<long long> nums;
    for(int i= 0 ; i<n+m ; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    for(int i = 0 ; i<nums.size() ; i++)
    {
        cout<<nums[i]<<" ";
    }
}