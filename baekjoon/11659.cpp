#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n, m;
    cin>>n>>m;

    vector<int> nums(n, 0);
    vector<int> sums(n+1, 0);
    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    for(int i = 0 ; i<n ; i++)
    {
        sums[i+1] = sums[i] + nums[i];
    }

    while(m--)
    {
        int x, y;
        cin>>x>>y;
        cout<<sums[y] - sums[x-1]<<'\n';
    }
}