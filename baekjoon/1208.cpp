#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int n, se;
vector<int> nums(40, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>se;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    int ans = 0;

    vector<long long> lis;

    

    cout<<ans;
}