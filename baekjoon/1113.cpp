#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > map;
vector<vector<bool> > group;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n, m;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void paintArea(int x, int y, int origin, int value)
{
    queue<pair<int, int> > q;
    map[x][y] = value;
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

            if(tx < 0 || ty < 0 || tx >= n || ty >= m)
            {
                continue;
            }
            else if(map[tx][ty] == origin)
            {
                map[tx][ty] = value;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

void matchWithGroup(vector<vector<bool> >& visited)
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(visited[i][j])
                group[i][j] = true;
        }
    }
}

void bfs(int x, int y)
{
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int minimum = 10;
    bool outOfBound = false;

    queue<pair<int, int> > q;
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

            if(tx < 0 || ty < 0 || tx >= n || ty >= m)
            {
                outOfBound = true;
                continue;
            }
            else if(map[tx][ty] == map[x][y] && !visited[tx][ty])
            {
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
            else if(map[tx][ty] > map[x][y])
            {
                minimum = min(minimum, map[tx][ty]);
                continue;
            }
            else if(map[tx][ty] < map[x][y])
            {
                outOfBound = true;
                continue;
            }
        }
    }


    matchWithGroup(visited);
    if(outOfBound || minimum==10)  
    {
        return;
    }
    paintArea(x, y, map[x][y], minimum);
    bfs(x, y);
}

int main()
{
    init();
    cin>>n>>m;
    int total = 0;

    map.resize(n, vector<int>(m ,0));
    group.resize(n, vector<bool>(m, false));

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    vector<vector<int> > original = map;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(original[i][j]==0)   {cout<<0; return 0;}
            if(!group[i][j])
            {
                bfs(i, j);
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(map[i][j] > original[i][j])
            {
                total += map[i][j] - original[i][j];
            }
        }
    }

    cout<<total;
}