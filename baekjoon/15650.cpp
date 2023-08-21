#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<vector<int> > ans;
int n, m;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cur, int cnt)
{
    if(cnt == 0)
    {
        sort(nums.begin(), nums.end());

        ans.push_back(nums);
        return;
    }

    if(n - cur < cnt)  return;

    for(int i = cur+1 ; i<=n ; i++)
    {
        nums.push_back(i);
        dfs(i, cnt-1);
        nums.pop_back();
    }
}

int main()
{
    init();

    cin>>n>>m;

    dfs(0, m);

    int n_size = ans.size();
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i<n_size ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}