#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;
vector<vector<int> > map(20, vector<int>(20, 0));
pair<int, int> shark;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int eaten = 0;
int shark_size = 2;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    int time = INT_MAX;
    pair<int, int> fish;

    q.push(shark);
    visited[shark.first][shark.second] = true;

    int cnt = 0;
    while(!q.empty())
    {
        int q_size = q.size();
        for(int k = 0 ; k<q_size ; k++)
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if(time <= cnt)
            {
                map[shark.first][shark.second] = 0;
                map[fish.first][fish.second] = 9;
                shark = fish;

                return time;
            }

            for(int i = 0 ; i<4 ; i++)
            {
                int tx = cx + dx[i];
                int ty = cy + dy[i];

                if(tx<0 || ty<0 || tx>=n || ty >=n) continue;
                if(!visited[tx][ty] && map[tx][ty] <= shark_size)
                {
                    q.push(make_pair(tx, ty));
                    visited[tx][ty] = true;

                    if(map[tx][ty] && map[tx][ty] < shark_size && time > cnt+1)
                    {
                        time = cnt+1;
                        fish = make_pair(tx, ty);
                    }
                    if(map[tx][ty] && map[tx][ty] < shark_size && time == cnt+1)
                    {
                        if(tx<fish.first || (tx==fish.first && ty<fish.second))
                        {
                            fish = make_pair(tx, ty);
                        }
                    }
                }
            }
        }
        cnt++;
    }

    return 0;
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

            if(map[i][j] == 9)  shark = make_pair(i, j);
        }
    }

    int ans = 0;
    while(true)
    {
        int val = bfs();
        if(!val)    break;
        ans += val;
        eaten++;
        if(eaten == shark_size)
        {
            shark_size++;
            eaten = 0;
        }
    }

    cout<<ans;
}