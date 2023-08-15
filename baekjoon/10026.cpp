#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<char> > screen(100, vector<char>(100, 0));
vector<vector<bool> > visited(100, vector<bool>(100, false));
vector<vector<bool> > visited_bc(100, vector<bool>(100, false));
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


void bfs_bc(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited_bc[x][y] = true;

    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = nx + dx[i];
            int ty = ny + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=n)
                continue;

            if(!visited_bc[tx][ty] && screen[tx][ty] == screen[x][y])
            {
                visited_bc[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
            else if(!visited_bc[tx][ty] && ((screen[tx][ty] == 'R' && screen[x][y] == 'G') || (screen[tx][ty] == 'G' && screen[x][y] == 'R') ) )
            {
                visited_bc[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
    
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = nx + dx[i];
            int ty = ny + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=n)
                continue;

            if(!visited[tx][ty] && screen[tx][ty] == screen[x][y])
            {
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
    
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>screen[i][j];
        }
    }

    int cnt = 0, cnt_bc = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(!visited[i][j])
            {
                bfs(i, j);
                cnt++;
            }
            if(!visited_bc[i][j])
            {
                bfs_bc(i, j);
                cnt_bc++;
            }
        }
    }

    cout<<cnt<<' '<<cnt_bc;
}
