#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void drawStar(vector<vector<char> >& pic, int n, int x, int y)
{
    if(n==1)
    {
        pic[x][y] = '*';
        return;
    }

    int third = n/3;
    for(int i = 0 ; i<n ; i+=third)
    {
        for(int j = 0 ; j<n ; j+=third)
        {
            if(i!= third || j!= third)
            {
                drawStar(pic, third, x+i, y+j);
            }
        }
    }
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<char> > pic(n, vector<char>(n, ' '));

    drawStar(pic, n, 0, 0);
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cout<<pic[i][j];
        }
        cout<<endl;
    }
}