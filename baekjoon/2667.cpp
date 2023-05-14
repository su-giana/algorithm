#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> >& map, int x, int y)
{
    int n = map.size();
    int ret = 0;
    vector<int> dx = {-1, 1, 0 ,0};
    vector<int> dy = {0, 0, -1, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    map[x][y] = 0;

    while(!q.empty())
    {

        pair<int, int> cur = q.front();
        q.pop();
        
        ret++;

        for(int i = 0 ; i<4 ; i++)
        {
            int temp_x = dx[i] + cur.first;
            int temp_y = dy[i] + cur.second;
            if(temp_x>=n || temp_x<0 || temp_y>=n || temp_y<0)
            {
                continue;
            }
            else if(map[temp_x][temp_y])
            {
                q.push(make_pair(temp_x, temp_y));
                map[temp_x][temp_y] = 0;
            }
        }
    }
    return ret;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<int> > map(n, vector<int>(n, 0));

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<n ; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    priority_queue<int, vector<int>, greater<int> > que;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(map[i][j])
            {
                que.push(bfs(map, i, j));
            }
        }
    }

    cout<<que.size()<<endl;
    while(!que.empty())
    {
        cout<<que.top()<<endl;;
        que.pop();
    }
}