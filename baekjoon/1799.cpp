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

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dfs(int x, int y, vector<pair<int, int> > bishops)
{
    if(y>=n)
    {
        x++;
        y = y%2 ? 0 : 1;
    }
    if(x>=n)
    {
        return bishops.size();
    }

    if(map_[x][y] && !lDiag[y - x + (n-1)] && !rDiag[x + y])
    {
        
    }

    return dfs(x, y+2, bishops);
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
    
    cout<<dfs(0, 0, {}) + dfs(0, 1, {});
}