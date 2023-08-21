#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> nums;
vector<bool> visited(8, false);
vector<vector<int> > total;
set<string> s;
vector<int> vals;
int n, m;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cnt)
{
    if(cnt == 0)
    {
        string ans = "";
        for(int i = 0 ; i<m ; i++)
        {
            ans += to_string(nums[i]) + " ";
        }
        
        if(s.find(ans) == s.end())
        {
            total.push_back(nums);
            s.insert(ans);
        }
        return;
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            nums.push_back(vals[i]);
            dfs(cnt-1);
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

    dfs(m);

    sort(total.begin(), total.end());

    int t = total.size();
    for(int i = 0 ; i<t ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<total[i][j]<<' ';
        }
        cout<<'\n';
    }

}