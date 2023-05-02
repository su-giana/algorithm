#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

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
    int n;
    cin>>n;

    vector<long long> nums;
    for(int i = 0 ; i<n ; i++)
    {
        long long num;
        cin>>num;

        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int cnt = 1, ans = 0, temp = 0;
    for(int i = 0 ; i<n-1 ; i++)
    {
        if(nums[i] != nums[i+1])
        {
            cnt = 1;
        }
        else
        {
            cnt++;
            if(cnt > ans)
            {
                ans = cnt;
                temp = i;
            }
        }
    }
    cout<<nums[temp];
}