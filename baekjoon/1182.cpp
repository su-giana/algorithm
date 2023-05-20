#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool isEqualsS(vector<int>& nums, vector<bool>& visited, int s)
{
    int n = nums.size();
    int sum = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(visited[i])
        {
            sum += nums[i];
        }
    }

    if(sum == s)    return true;
    return false;
}

int dfs(vector<int>& nums, vector<bool>& visited, int start, int s)
{
    int n = nums.size();
    int ans = 0;
    if(accumulate(visited.begin(), visited.end(), 0)!=0 && isEqualsS(nums, visited, s)) ans += 1;

    for(int i = start ; i<n ; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            ans += dfs(nums, visited, i+1, s);
            visited[i] = false;
        }
    }
    return ans;
}

int main()
{
    init();

    int n, s;
    cin>>n>>s;

    vector<int> nums(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    vector<bool> visited(n, false);

    cout<<dfs(nums, visited, 0, s);
}