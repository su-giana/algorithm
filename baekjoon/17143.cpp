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
        if(shark.row - shark.speed >= 1)
        {
            shark.row = shark.row - shark.speed;
        }
        else
        {
            int mod = (shark.speed - r + shark.row - 1) % (r-1);
            int div = (shark.speed - r + shark.row - 1) / (r-1);

            if(div % 2 == 0)
            {
                shark.dir = 4;
                shark.row = 2 + mod;
            }
            else
            {
                shark.row = r - 1 - mod;
            }
        }
    }
    else if(shark.dir == 2)
    {
        if(shark.speed + shark.row <= r)
        {
            shark.row = shark.row + shark.speed;
        }
        else
        {
            int mod = (shark.speed - shark.row) % (r-1);
            int div = (shark.speed - shark.row) / (r-1);

            if(div % 2 == 0)
            {
                shark.dir = 3;
                shark.row = r - 1 - mod;
                
            }
            else
            {
                shark.row = 2 + mod;
            }
        }
    }
    else if(shark.dir == 3)
    {
        if(shark.speed + shark.col <= c)
        {
            shark.col = shark.col + shark.speed;
        }
        else
        {
            int mod = (shark.speed - c + shark.col - 1) % (c-1);
            int div = (shark.speed - c + shark.col - 1) / (c-1);

            if(div % 2 == 0)
            {
                shark.dir = 4;
                shark.col = c - 1 - mod;
                
            }
            else
            {
                shark.col = 2 + mod;
            }
        }
    }
    else
    {
        if(shark.speed <= shark.col)
        {
            shark.col = shark.col - shark.speed;
        }
        else
        {
            int mod = (shark.speed - shark.col) % (c-1);
            int div = (shark.speed - shark.col) / (c-1);

            if(div % 2 == 0)
            {
                shark.dir = 3;
                shark.col = 2 + mod;
            }
            else
            {
                shark.col = c - 1 - mod;
            }
        }
    }
}

int bfs()
{
    int ans = 0;

    while(king < c)
    {

        for(int i = 1 ; i<=r ; i++)
        {
            for(int j = 1 ; j<=c ; j++)
            {
                cout<<map[i][j].weight<<' ';
            }
            cout<<endl;
        }
        cout<<endl;

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