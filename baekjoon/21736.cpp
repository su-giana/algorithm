#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > map(600, vector<int>(600, 0));
pair<int, int> start;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string bfs()
{
    queue<pair<int, int> > q;
    q.push(start);
    int cnt = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=m)
                continue;

            if(map[tx][ty] == 0)
            {
                map[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
            else if(map[tx][ty] == 2)
            {
                map[tx][ty] = 1;
                q.push(make_pair(tx, ty));
                cnt++;
            }
        }
    }

    string ans = cnt>0 ? to_string(cnt) : "TT";
    return ans;
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
            if(s[j] == 'P')
            {
                map[i][j] = 2;
            }
            else if(s[j] == 'I')
            {
                map[i][j] = 1;
                start.first = i;
                start.second = j;
            }
            else if(s[j]=='X')
            {
                map[i][j] = -1;
            }
        }
    }

    cout<<bfs();
}