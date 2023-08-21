#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<bool> visited(8, false);
vector<vector<int> > ans;
vector<int> vals;
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
        ans.push_back(nums);
        return;
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            nums.push_back(vals[i]);
            dfs(i, cnt-1);
            nums.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        int val;
        cin>>val;
        vals.push_back(val);
    }

    sort(vals.begin(), vals.end());

    dfs(-1, m);

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