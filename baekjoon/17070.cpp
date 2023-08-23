#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > map(16, vector<int>(16, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs()
{
    queue<vector<int> > q;
    q.push({0, 1, 0});
    int cnt = 0;

    while(!q.empty())
    {
        int cx = q.front()[0];
        int cy = q.front()[1];
        int dir = q.front()[2];
        q.pop();

        if(cx==n-1 && cy == n-1)
        {
            cnt++;
            continue;
        }

        int vx = cx + 1;
        int hy = cy + 1;
        
        if(hy < n && (dir == 0 || dir == 2))
        {
            if(map[cx][hy] == 0)
            {
                q.push({cx, hy, 0});
            }
        }
        if(vx<n && (dir == 1 || dir == 2))
        {
            if(map[vx][cy] == 0)
            {
                q.push({vx, cy, 1});
            }
        }
        if(vx < n && hy < n)
        {
            if(!map[vx][cy] && !map[cx][hy] && !map[vx][hy])
            {
                q.push({vx, hy, 2});
            }
        }
    }

    cout<<cnt;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map[i][j];
        }
    }

    bfs();
}