#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dfs(vector<vector<int> >& map)
{
    int n = map[0].size();
    int m = map.size();
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    map[0][0] = 1;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        int order = map[cur.first][cur.second] + 1;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = dx[i] + cur.second;
            int ty = dy[i] + cur.first;
            if(tx>=n || tx<0 || ty>=m || ty<0)  continue;
            else if(map[ty][tx]!=0 && map[ty][tx] > order)
            {
                q.push(make_pair(ty, tx));
                map[ty][tx] = order;
            }
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int> > map(n, vector<int>(m, 0));
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            if(s[j] - '0')   map[i][j] = INT_MAX;
        }
    }


    dfs(map);

    cout<<map[n-1][m-1];
}