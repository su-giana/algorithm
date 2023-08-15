#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

int m, n, h;
vector<vector<vector<int> > > boxes(100, vector<vector<int> >(100, vector<int>(100, 0)));
vector<vector<int> > initial;
vector<int> dx = {-1, 1, 0, 0, 0, 0};
vector<int> dy = {0, 0, -1, 1, 0, 0};
vector<int> dz = {0, 0, 0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<vector<int> > q;

    int i_size = initial.size();
    for(int i = 0 ; i<i_size ; i++)
    {
        q.push(initial[i]);
    }

    int cnt = 0;

    while(!q.empty())
    {
        bool done = true;
        for(int k = 0 ; k<h && done ; k++)
        {
            for(int i = 0 ; i<n && done ; i++)
            {
                for(int j = 0 ; j<m && done ; j++)
                {
                    if(boxes[k][i][j] == 0)
                    {
                        done = false;
                        break;
                    }
                }
            }
        }
        if(done)
        {
            return cnt;
        }

        int q_size = q.size();

        for(int k = 0 ; k<q_size ; k++)
        {
            int z = q.front()[0], x = q.front()[1], y = q.front()[2];
            q.pop();

            for(int i = 0 ; i<6 ; i++)
            {
                int tz = z + dz[i];
                int tx = x + dx[i];
                int ty = y + dy[i];

                if(tz<0 || tx<0 || ty<0 || tz>=h || tx>=n || ty>=m)
                    continue;
                
                if(boxes[tz][tx][ty] == 0)
                {
                    boxes[tz][tx][ty] = 1;
                    q.push({tz, tx, ty});
                }
            }
        }

        cnt++;
    }

    return -1;
}

int main()
{
    init();

    cin>>m>>n>>h;

    for(int k = 0 ; k<h ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                cin>>boxes[k][i][j];

                if(boxes[k][i][j]==1)
                {
                    initial.push_back({k, i, j});
                }
            }
        }
    }

    cout<<bfs();
}