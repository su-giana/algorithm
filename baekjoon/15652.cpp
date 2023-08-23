#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums(8, 0);
set<vector<int> > s;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cnt, vector<int> arr)
{
    if(cnt==0)
    {
        for(int i = 1 ; i<m ; i++)
        {
            if(arr[i-1] > arr[i])
            {
                return;
            }
        }
        s.insert(arr);
        return;
    }


    for(int i = 1 ; i<=n ; i++)
    {
        arr.push_back(i);
        dfs(cnt-1, arr);
        arr.pop_back();
    }
}

int main()
{
    init();

    cin>>n>>m;

    dfs(m, vector<int>());

    vector<vector<int> > ans(s.begin(), s.end());
    sort(ans.begin(), ans.end());

    int a_size = ans.size();
    for(int i = 0 ; i<a_size ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}