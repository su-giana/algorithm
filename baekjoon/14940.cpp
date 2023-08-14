#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<int> > map(1000, vector<int>(1000, 0));
vector<vector<bool> > visited(1000, vector<bool>(1000, false));
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int n, m;

void ur_bfs(int x, int y)
{
    queue<pair<int, int> > q;
    map[x][y] = -1;
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = curX + dx[i];
            int ty = curY + dy[i];

            if(tx < 0 || ty<0 || tx>=n || ty>=m)
                continue;
            
            if(!visited[tx][ty] && map[tx][ty] != 0)
            {
                map[tx][ty] = -1;
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    visited[x][y] = true;
    map[x][y] = 0;
    q.push(make_pair(x, y));

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = curX + dx[i];
            int ty = curY + dy[i];

            if(tx < 0 || ty<0 || tx>=n || ty>=m)
                continue;
            
            if((map[tx][ty]!=0 && !visited[tx][ty]) || map[tx][ty] > map[curX][curY] + 1)
            {
                map[tx][ty] = map[curX][curY] + 1;
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

int main()
{
    init();

    cin>>n>>m;
    pair<int, int> start;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cin>>map[i][j];

            if(map[i][j] == 2)
            {
                start = make_pair(i, j);
            }
        }
    }

    bfs(start.first, start.second);

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(map[i][j] != 0 && !visited[i][j])
            {
                ur_bfs(i, j);
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
}