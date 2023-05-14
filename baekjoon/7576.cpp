#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> >& map, vector<pair<int, int> > ripes)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int m = map[0].size();
    int n = map.size();
    int t = ripes.size();
    int dates = 0;
    
    queue<vector<int> > q;
    for(int i = 0 ; i<t ; i++)
    {
        q.push(vector<int>{ripes[i].first, ripes[i].second, 0});
    }
    
    while(!q.empty())
    {
        int y = q.front()[0];
        int x = q.front()[1];
        int date = q.front()[2];
        dates = max(date, dates);
        q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int ty = dy[i] + y;
            int tx = dx[i] + x;
            if(tx>=m || tx<0 || ty>=n || ty<0)
            {
                continue;
            }
            else if(map[ty][tx] == 0)
            {
                q.push(vector<int>{ty, tx, date+1});
                map[ty][tx] = 1;
            }
        }
    }
    return dates;
}

int main()
{
    int m, n;
    cin>>m>>n;

    vector<vector<int> > boxes(n, vector<int>(m, 0));
    vector<pair<int, int> > ripes;
    bool noTalLRipe = false;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int box;
            cin>>box;
            boxes[i][j] = box;
        }
    }
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(boxes[i][j] == 1)
            {
                ripes.push_back(make_pair(i, j));
            }
        }
    }
    int ans = bfs(boxes, ripes);

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(boxes[i][j] == 0)
            {
                noTalLRipe = true;
                break;
            }
        }
        if(noTalLRipe)  break;
    }
    if(noTalLRipe) cout<<-1;
    else        cout<<ans;
}