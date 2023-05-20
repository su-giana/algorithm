#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solveSdoku(vector<vector<int> >& sdoku, int x, int y)
{
    vector<bool> visited(10, false);

    for(int i = 0 ; i<9 ; i++)
    {
        visited[sdoku[i][y]] = true;
        visited[sdoku[x][i]] = true;
    }

    for(int i = x/3*3 ; i<x/3*3 + 3 ; i++)
    {
        for(int j = y/3*3 ; j<y/3*3 + 3 ; j++)
        {
            visited[sdoku[i][j]] = true;
        }
    }

    for(int i = 1 ; i<10 ; i++)
    {
        if(!visited[i])
        {
            sdoku[x][y] = i;
        }
    }
}

void solveSdoku(vector<vector<int> >& sdoku)
{
    for(int i = 0 ; i<9 ; i++)
    {
        for(int j = 0 ; j<9 ; j++)
        {
            if(sdoku[i][j] == 0)    solveSdoku(sdoku, i, j);
        }
    }
}

int main()
{
    init();

    vector<vector<int> > sdoku(9, vector<int>(9, 0));
    for(int i = 0 ; i<9 ; i++)
    {
        for(int j = 0 ; j<9 ; j++)
        {
            int num;
            cin>>num;
            sdoku[i][j] = num;
        }
    }

    solveSdoku(sdoku);

    for(int i = 0 ; i<9 ; i++)
    {
        for(int j = 0 ; j<9 ; j++)
        {
            cout<<sdoku[i][j];
            if(j!=8)
            {
                cout<<' ';
            }
        }
        cout<<'\n';
    }
}