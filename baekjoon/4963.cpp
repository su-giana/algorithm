#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> >& map, int y, int x)
{
    int w = map[0].size();
    int h = map.size();
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, -1, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    map[y][x] = 0;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0 ; i<8 ; i++)
        {
            int tx = dx[i] + cur.second;
            int ty = dy[i] + cur.first;
            if(tx>=w || tx<0 || ty>=h || ty<0)
            {
                continue;
            }
            else if(map[ty][tx])
            {
                q.push(make_pair(ty, tx));
                map[ty][tx] = 0;
            }
        }
    }
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    while(true)
    {
        int w, h;
        cin>>w>>h;
        if(!w && !h)    break;

        vector<vector<int> > map(h, vector<int>(w, 0));
        for(int i = 0 ; i<h ; i++)
        {
            for(int j = 0 ; j<w ; j++)
            {
                int part;
                cin>>part;
                map[i][j] = part;
            }
        }

        int ans = 0;
        for(int i = 0 ; i<h ; i++)
        {
            for(int j = 0 ; j<w ; j++)
            {
                if(map[i][j])
                {
                    bfs(map, i, j);
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }
}