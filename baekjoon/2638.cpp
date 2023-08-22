#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > map(100, vector<int>(100, 0));
vector<vector<bool> > visited(100, vector<bool>(100, false));
vector<pair<int, int> > melted;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    vector<vector<int> > cheese(n, vector<int>(m, 0));

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

            if(map[tx][ty] == 0 && !visited[tx][ty])
            {
                q.push(make_pair(tx, ty));
                visited[tx][ty] = true;
            }
            else if(map[tx][ty] == 1)
            {
                cheese[tx][ty]++;
                if(cheese[tx][ty] == 2)
                {
                    melted.push_back(make_pair(tx, ty));
                }
            }
        }
    }
}

int main()
{
    init();

    cin>>n>>m;

    int cnt = 0;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cin>>map[i][j];
        }
    }

    while(true)
    {
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(!(i==0 || j==0 || i==n-1 || j==m-1)) continue;
                if(!visited[i][j] && !map[i][j])
                {
                    bfs(i, j);
                }
            }
        }

        if(melted.size() == 0)
        {
            break;
        }

        for(pair<int, int> melt : melted)
        {
            map[melt.first][melt.second] = 0;
        }
        melted.clear();
        visited = vector<vector<bool> >(n, vector<bool>(m, false));
        cnt++;
    }

    cout<<cnt;
}