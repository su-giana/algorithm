#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<vector<vector<char> > > chess(2, vector<vector<char> > (8, vector<char>(8, ' ')));
vector<vector<char> > map(50, vector<char>(50, ' '));

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void initString()
{
    for(int i = 0 ; i<8 ; i++)
    {
        for(int j = 0 ; j<8 ; j++)
        {
            if((j%2 == 1 && i%2 == 1) || (j%2==0 && i%2==0))
            {
                chess[0][i][j] = 'B';
                chess[1][i][j] = 'W';
            }
            else
            {
                chess[0][i][j] = 'W';
                chess[1][i][j] = 'B';
            }
        }
    }
}

int getChanged(int x, int y)
{
    int minimum = 65;
    for(int k = 0 ; k<2 ; k++)
    {
        int cnt = 0;
        for(int i = 0 ; i<8 ; i++)
        {
            for(int j = 0 ; j<8 ; j++)
            {
                if(map[x + i][y + j] != chess[k][i][j])
                {
                    cnt++;
                }
            }
        }
        minimum = min(minimum, cnt);
    }
    return minimum;
}

int main()
{
    init();
    initString();

    cin>>n>>m;
    int answer = 65;

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            map[i][j] = s[j];
        }
    }

    for(int i = 0 ; i<n-7 ; i++)
    {
        for(int j = 0 ; j<m-7 ; j++)
        {
            answer = min(answer, getChanged(i, j));
        }
    }

    cout<<answer;
}