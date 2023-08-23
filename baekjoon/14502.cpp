#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > map(8, vector<int>(8, 0));
vector<pair<int, int> > virus;
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
    queue<pair<int, int> > q;
    int v_size = virus.size();
    vector<vector<int> > lab = map;
    for(int i = 0 ; i<v_size ; i++)
    {
        int x = virus[i].first;
        int y = virus[i].second;

        q.push(virus[i]);
    }

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];

            if(tx<0 || ty<0 || tx>=n || ty>=m)  continue;

            if(lab[tx][ty] == 0)
            {
                lab[tx][ty] = 2;
                q.push(make_pair(tx, ty));
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(!lab[i][j])  ans++;
        }
    }

    return ans;
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cin>>map[i][j];

            if(map[i][j] == 2)  virus.push_back(make_pair(i, j));
        }
    }

    int ans = 0;
    for(int i = 0 ; i<n*m ; i++)
    {
        if(map[i/m][i%m] != 0)  continue;
        map[i/m][i%m] = 1;
        for(int j = 0 ; j<n*m ; j++)
        {
            if(i==j)    continue;
            if(map[j/m][j%m] != 0)  continue;
            map[j/m][j%m] = 1;
            for(int k = 0 ; k<n*m ; k++)
            {
                if(j==k || i==j)    continue;
                if(map[k/m][k%m])   continue;
                map[k/m][k%m] = 1;

                ans = max(ans, bfs());

                map[k/m][k%m] = 0;
            }
            map[j/m][j%m] = 0;
        }
        map[i/m][i%m] = 0;
    }

    cout<<ans;
}