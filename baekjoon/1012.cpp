#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void bfs(vector<vector<int> >& map, int x, int y)
{
    int n = map.size();
    int m = map[0].size();

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    map[x][y] = 0;

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = curX + dx[i];
            int ty = curY + dy[i];

            if(tx < 0 || ty < 0 || tx >= n || ty >= m)
                continue;

            if(map[tx][ty] == 1)
            {
                map[tx][ty] = 0;
                q.push(make_pair(tx, ty));
            }
        }

    }
}

int main()
{
    init();

    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>k;

        int cnt = 0;
        vector<vector<int> > map(n, vector<int>(m, 0));
        while(k--)
        {
            int x, y;
            cin>>x>>y;
            map[y][x] = 1;
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(map[i][j] == 1)
                {
                    cnt++;
                    bfs(map, i, j);
                }
            }
        }
        cout<<cnt<<'\n';
    }
}