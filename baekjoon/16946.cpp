#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
int ord = 1;
vector<vector<int> > map_(1000, vector<int>(1000, 0));
vector<vector<int> > visited(1000, vector<int>(1000, 0));
vector<vector<int> > root(1000, vector<int>(1000, 0));
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void paint(int curX, int curY, int cnt)
{
    queue<pair<int, int> > q;
    q.push(make_pair(curX, curY));
    visited[curX][curY] = cnt;
    root[curX][curY] = ord;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

            if(visited[tx][ty]==-1)
            {
                visited[tx][ty] = cnt;
                root[tx][ty] = ord;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

void dfs(int curX, int curY)
{
    queue<pair<int, int> > q;
    q.push(make_pair(curX, curY));
    int cnt = 1;
    visited[curX][curY] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

            if(map_[tx][ty] == 0 && !visited[tx][ty])
            {
                visited[tx][ty] = -1;
                q.push(make_pair(tx, ty));
                cnt++;
            }
        }
    }

    paint(curX, curY, cnt);
    ord++;
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            map_[i][j] = s[j] - '0';
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(map_[i][j] == 0 && !visited[i][j])
            {
                dfs(i, j);
            }
        }
    }

    vector<vector<int> > ans(n, vector<int>(m, 0));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(map_[i][j] == 1)
            {
                set<int> s;
                ans[i][j] = 1;
                for(int k = 0 ; k<4 ; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

                    if(visited[tx][ty] && s.find(root[tx][ty]) == s.end())
                    {
                        ans[i][j] = (ans[i][j] + visited[tx][ty]) % 10;
                        s.insert(root[tx][ty]);
                    }
                }
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}