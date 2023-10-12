#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define pii pair<int, int>

using namespace std;

int n, m;
vector<vector<char> > map_(10, vector<char>(10, ' '));
pii red, blue;
set<pair<pii, pii> > s;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

pair<pii, pii> tiltBoard(pair<pii, pii>& balls, int direction)
{
    pair<pair<pii, char>, pair<pii, char> > order;
    if(direction == 0)
    {
        order = balls.first.first <= balls.second.first ? make_pair(make_pair(balls.first, 'R'), make_pair(balls.second, 'B')): make_pair(make_pair(balls.second, 'B'), make_pair(balls.first, 'R'));
    }
    else if(direction == 1)
    {
        order = balls.first.first >= balls.second.first ? make_pair(make_pair(balls.first, 'R'), make_pair(balls.second, 'B')): make_pair(make_pair(balls.second, 'B'), make_pair(balls.first, 'R'));
    }
    else if(direction == 2)
    {
        order = balls.first.second <= balls.second.second ? make_pair(make_pair(balls.first, 'R'), make_pair(balls.second, 'B')): make_pair(make_pair(balls.second, 'B'), make_pair(balls.first, 'R'));
    }
    else
    {
        order = balls.first.second >= balls.second.second ? make_pair(make_pair(balls.first, 'R'), make_pair(balls.second, 'B')): make_pair(make_pair(balls.second, 'B'), make_pair(balls.first, 'R'));
    }

    while(true)
    {
        int tx1 = order.first.first.first + dx[direction];
        int ty1 = order.first.first.second + dy[direction];
        char color = order.first.second;

        if(tx1<0 || ty1<0 || tx1>=n || ty1>=m || map_[tx1][ty1] == '#')  break;
        else if(tx1 == order.second.first.first && ty1 == order.second.first.second)    break;
        else if(map_[tx1][ty1] == 'O' && color == 'R')    { order.first.first = make_pair(-1, -1); break; }
        else if(map_[tx1][ty1] == 'O' && color == 'B')    return make_pair(make_pair(-2, -2), make_pair(-2, -2));
        else if(map_[tx1][ty1] == '.')  order.first.first = make_pair(tx1, ty1);
    }
    while(true)
    {
        int tx1 = order.second.first.first + dx[direction];
        int ty1 = order.second.first.second + dy[direction];
        char color = order.second.second;

        if(tx1<0 || ty1<0 || tx1>=n || ty1>=m || map_[tx1][ty1] == '#')  break;
        else if(tx1 == order.first.first.first && ty1 == order.first.first.second)    break;
        else if(map_[tx1][ty1] == 'O' && color == 'R')    { order.second.first = make_pair(-1, -1); break; }
        else if(map_[tx1][ty1] == 'O' && color == 'B')    return make_pair(make_pair(-2, -2), make_pair(-2, -2));
        else if(map_[tx1][ty1] == '.')  order.second.first = make_pair(tx1, ty1);
    }
    
    return order.first.second == 'R' ? make_pair(order.first.first, order.second.first) : make_pair(order.second.first, order.first.first);
}

int bfs()
{
    int cnt = 1;
    queue<pair<pii, pii> > q;

    q.push(make_pair(red, blue));
    s.insert(make_pair(red, blue));

    while(!q.empty())
    {
        if(cnt>10)  return -1;
        int q_size = q.size();
        for(int k = 0 ; k<q_size ; k++)
        {
            pair<pii, pii> cur = q.front();
            q.pop();

            for(int i = 0 ; i<4 ; i++)
            {
                pair<pii, pii> next = tiltBoard(cur, i);
                if(next.first.first == -1)    return cnt;
                else if(next.first.first == -2)   continue;

                if(s.find(next) == s.end())
                {
                    q.push(next);
                    s.insert(next);
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
        for(int j = 0 ;j<m ; j++)
        {
            cin>>map_[i][j];
            if(map_[i][j] == 'R')
            {
                red = make_pair(i, j);
                map_[i][j] = '.';
            }
            else if(map_[i][j] == 'B')
            {
                blue = make_pair(i, j);
                map_[i][j] = '.';
            }
        }
    }

    cout<<bfs();
}