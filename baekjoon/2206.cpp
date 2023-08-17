#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<int> > graph(1000, vector<int>(1000, 0));
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<vector<int> > q;
    vector<vector<vector<bool> > > visited(2, vector<vector<bool> >(n, vector<bool>(m, false)));
    q.push({0, 0, 1});
    visited[true][0][0] = 1;
    int cnt = 1;

    while(!q.empty())
    {
        int q_size = q.size();
        for(int k = 0 ; k<q_size ; k++)
        {
            int x = q.front()[0];
            int y = q.front()[1];
            bool wall = q.front()[2];
            q.pop();

            if(x == n-1 && y == m-1)    return cnt;

            for(int i = 0 ; i<4 ; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

                if(graph[tx][ty] == 0 && !visited[wall][tx][ty])
                {
                    visited[wall][tx][ty] = true;
                    q.push({tx, ty, wall});
                }
                else if(graph[tx][ty] == 1 && !visited[wall][tx][ty] && wall)
                {
                    visited[wall][tx][ty] = true;
                    q.push({tx, ty, false});
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
    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    cout<<bfs();
}