#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;
int n;
unordered_map<int, int> map_;
vector<int> ans;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    init();

    cin>>n;

    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        ans.push_back(num);
        s.insert(num);
    }

    vector<int> nums(s.begin(), s.end());
    sort(nums.begin(), nums.end());

    int n_size = nums.size();
    for(int i = 0 ; i<n_size ; i++)
    {
        map_.insert(make_pair(nums[i], i));
    }

    for(int i = 0 ; i<n ; i++)
    {
        cout<<map_[ans[i]]<<" ";
    }
}