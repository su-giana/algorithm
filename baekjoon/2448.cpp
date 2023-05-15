#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void drawTriangle(vector<vector<char> >& pic, int x, int y)
{
    int center = y+2;
    for(int i = 0 ; i<3 ; i++)
    {
        pic[x+i][center + i] = '*';
        pic[x+i][center - i] = '*';
        pic[x+2][center-1+i] = '*';
    }
}

void drawTriangles(vector<vector<char> >& pic, int n, int x, int y)
{
    if(n==3)
    {
        drawTriangle(pic, x, y);
        return;
    }

    int div = n/2;
    drawTriangles(pic, div, x, y + div);
    drawTriangles(pic, div, x+div, y);
    drawTriangles(pic, div, x+div, y+n);
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<char> > pic(n, vector<char>(2*n, ' '));

    drawTriangles(pic, n, 0, 0);

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<2*n ; j++)
        {
            cout<<pic[i][j];
        }
        cout<<endl;
    }
}