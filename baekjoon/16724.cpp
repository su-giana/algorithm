#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int ans = 0;
int cur = 1;
vector<vector<char> > map(1000, vector<char>(1000, '0'));
vector<vector<int> > visited(1000, vector<int>(1000, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs(int i, int j)
{
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    visited[i][j] = cur;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int tx = x;
        int ty = y;

        if(map[x][y] == 'L')
        {
            ty -= 1;          
        }
        else if(map[x][y] == 'R')
        {
            ty += 1;
        }
        else if(map[x][y] == 'U')
        {
            tx -= 1;
        }
        else
        {
            tx += 1;
        }

        if(visited[tx][ty] == cur)
        {
            ans++;
            return;
        }
        if(visited[tx][ty] > 0)
        {
            return;
        }
        else
        {
            visited[tx][ty] = cur;
            q.push(make_pair(tx, ty));
        }
    }
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)  cin>>map[i][j];
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(!visited[i][j])
            {
                bfs(i, j);
                cur++;
            }
        }
    }

    cout<<ans;
}