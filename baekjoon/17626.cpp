#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

vector<int> ans(50001, INT_MAX);
vector<int> nums;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(int cur, int depth)
{
    if(ans[cur] <= depth)
    {
        return;
    }

    ans[cur] = depth;

    int n_size = nums.size();

    for(int i = n_size-1 ; i>=0 ; i--)
    {
        if(cur + nums[i] <= n)
        {
            solve(cur+nums[i], depth+1);
        }
    }
}

int main()
{
    init();

    cin>>n;

    for(int i = 1 ; i*i<=50000 ; i++)
    {
        nums.push_back(i*i);
    }

    solve(0, 0);

    cout<<ans[n];
}