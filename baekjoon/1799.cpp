#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > map_(10, vector<int>(10, 0));
vector<bool> lDiag(22, false);
vector<bool> rDiag(22, false);
vector<int> ans(2, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int x, int y, int cnt, int color)
{
    if(y>=n)
    {
        x++;
        y = y%2 ? 0 : 1;
    }
    if(x>=n)
    {
        ans[color] = max(ans[color], cnt);
        return;
    }

    if(map_[x][y] && !lDiag[y - x + (n-1)] && !rDiag[x + y])
    {
        lDiag[y - x + (n-1)] = rDiag[x + y] = true;
        dfs(x, y+2, cnt+1, color);
        lDiag[y - x + (n-1)] = rDiag[x + y] = false;
    }

    dfs(x, y+2, cnt, color);
}

int main()
{
    init();

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map_[i][j];
        }
    }

    if(n==1)    { cout<<map_[0][0]; return 0; }
    
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    cout<<ans[0] + ans[1];
}