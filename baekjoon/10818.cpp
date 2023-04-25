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
        int a;
        cin>>a;
        
        nums.push_back(a);
    }
    
    cout<<*max_element(nums.begin(), nums.end())<<" "<<*min_element(nums.begin(), nums.end());
    return 0;
}