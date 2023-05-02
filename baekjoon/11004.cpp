#include <iostream>
#include <vector>
#include <queue>
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
    int n, k;
    cin>>n>>k;

    vector<long long> nums;
    for(int i = 0 ; i<n ; i++)
    {
        long long num;
        cin>>num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    cout<<nums[k-1];
}