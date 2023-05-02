#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

    vector<int> nums(10001, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums[num]++;
    }

    for(int i = 1 ; i<=10000 ; i++)
    {
        for(int j = 0 ; j<nums[i] ; j++)
        {
            cout<<i<<'\n';
        }
    }
}