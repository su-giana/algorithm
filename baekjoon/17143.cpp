#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Shark
{
public:
    int row;
    int col;
    int dir;
    int speed;
    int weight;

    Shark(int r_, int c_, int d_, int s_, int w_)
    {
        row = r_;
        col = c_;
        dir = d_;
        speed = s_;
        weight = w_;
    }
};

int r, c, m;
int king = 1;
vector<vector<Shark> > map(101, vector<Shark>(101, Shark(0, 0, 0, 0, 0)));

void moveShark(Shark& shark)
{
    if(shark.dir == 1)
    {
        int gap = shark.row;
        int power = shark.speed;

        if(gap>power)
        {
            shark.row -= shark.speed;
            return;
        }
        power -= gap;

        int swamp = (power / (r-1)) % 2;
        if(swamp == 0)
        {
            shark.dir = 2;
            shark.row = 2 + power % (r-1);
        }
        else
        {
            shark.row = r - 1 - power % (r-1);
        }
    }
    else if(shark.dir == 2)
    {
        int gap = r - shark.row;
        int power = shark.speed;

        if(gap>=power)
        {
            shark.row += shark.speed;
            return;
        }
        power -= gap;

        int swamp = (power / (r-1)) % 2;
        if(swamp == 0)  // (2~r)
        {
            shark.dir = 1;
            shark.row = r - power % (r-1);
        }
        else    // (1~r-1)
        {
            shark.row = 1 + power % (r-1);
        }
    }
    else if(shark.dir == 3)
    {
        int gap = c - shark.col;
        int power = shark.speed;

        if(gap>=power)
        {
            shark.col += shark.speed;
            return;
        }
        power -= gap;

        int swamp = (power / (c-1)) % 2;
        if(swamp == 0)
        {
            shark.dir = 4;
            shark.col = c - power % (c-1);
        }
        else
        {
            shark.col = 1 + power % (c-1);
        }
    }
    else
    {
        int gap = shark.col;
        int power = shark.speed;

        if(gap>power)
        {
            shark.col -= shark.speed;
            return;
        }
        power -= gap;

        int swamp = (power / (c-1)) % 2;
        if(swamp == 0)
        {
            shark.dir = 3;
            shark.col = 2 + power % (c-1);
        }
        else
        {
            shark.col = c - 1 - power % (c-1);
        }
    }
}

int bfs()
{
    int ans = 0;

    while(king <= c)
    {
        for(int i = 1 ; i<=r ; i++)
        {
            if(map[i][king].weight > 0)
            {
                ans += map[i][king].weight;
                map[i][king] = Shark(0, 0, 0, 0, 0);
                break;
            }
        }

        vector<vector<Shark> > tmp(r+1, vector<Shark>(c+1, Shark(0, 0, 0, 0, 0)));

        for(int i = 1 ; i<=r ; i++)
        {
            for(int j = 1 ; j<=c; j++)   
            {
                Shark cur = map[i][j];

                if(cur.weight > 0)
                {
                    moveShark(cur);
                    if(tmp[cur.row][cur.col].weight < cur.weight)
                    {
                        tmp[cur.row][cur.col] = cur;
                    }
                }
            }
        }

        map = tmp;

        king++;
    }

    return ans;
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

    cin>>r>>c>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b, s, d, z;
        cin>>a>>b>>s>>d>>z;
        
        if(map[a][b].weight < z)
        {
            map[a][b] = Shark(a, b, d, s, z);
        }
    }

    cout<<bfs();
}