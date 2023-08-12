#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > map(500, vector<int>(500, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<pair<int, int> > > polynomio = {
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(0,2), make_pair(0,3)
    },
    {
        make_pair(0, 0), make_pair(1, 0), make_pair(2, 0), make_pair(3, 0)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(1,0), make_pair(1,1)
    },

    {
        make_pair(0, 0), make_pair(1, 0), make_pair(2,0), make_pair(2,1)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), make_pair(1, 0)
    },
    {
        make_pair(2, 0), make_pair(0, 1), make_pair(1, 1), make_pair(2, 1)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), make_pair(1, 2)
    },
    {
        make_pair(0, 0), make_pair(1, 0), make_pair(1,1), make_pair(1,2)
    },
    {
        make_pair(0, 2), make_pair(1, 0), make_pair(1, 1), make_pair(1, 2)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(1, 1), make_pair(2, 1)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(1, 0), make_pair(2, 0)
    },


    {
        make_pair(0, 0), make_pair(1, 0), make_pair(1,1), make_pair(2,1)
    },
    {
        make_pair(1, 0), make_pair(0, 1), make_pair(1,1), make_pair(0,2)
    },
    {
        make_pair(0, 0), make_pair(0, 1), make_pair(1,1), make_pair(1,2)
    },
    {
        make_pair(0, 1), make_pair(1, 0), make_pair(1,1), make_pair(2,0)
    },

    {
        make_pair(0, 0), make_pair(0, 1), make_pair(0,2), make_pair(1,1)
    },
    {
        make_pair(1, 0), make_pair(1, 1), make_pair(1,2), make_pair(0,1)
    },
    {
        make_pair(1, 0), make_pair(0, 1), make_pair(1,1), make_pair(2,1)
    },
    {
        make_pair(0, 0), make_pair(1, 0), make_pair(2,0), make_pair(1,1)
    }
};

void changeDirection(int k)
{
    polynomio[k].push_back(polynomio[k].front());
    polynomio[k].erase(polynomio[k].begin());
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int num;
            cin>>num;
            map[i][j] = num;
        }
    }

    long long ans = 0;
    int p_size = polynomio.size();
    for(int k = 0 ; k<p_size ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                for(int dir = 0 ; dir<4 ; dir++)
                {
                    changeDirection(k);
                    long long weight = 0;

                    for(int l = 0 ; l<4 ; l++)
                    {
                        int dx = polynomio[k][l].first;
                        int dy = polynomio[k][l].second;

                        int tx = i + dx;
                        int ty = j + dy;

                        if(tx<0 || ty<0 || tx>=n || ty>=m)
                        {
                            weight = 0;
                            break;
                        }
                        weight += map[tx][ty];
                    }
                    ans = max(ans, weight);
                }
            }
        }
    }
    cout<<ans;
}