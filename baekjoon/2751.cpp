#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums;
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    for(int i = 0 ; i<n ; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}