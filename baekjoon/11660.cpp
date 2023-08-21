#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map(1024+1, vector<int>(1024+1, 0));
int n, m;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getArea(int x1, int y1, int x2, int y2)
{
    return map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            int val;
            cin>>val;

            map[i+1][j+1] = val + map[i][j+1] + map[i+1][j] - map[i][j];
        }
    }

    while(m--)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<getArea(x1, y1, x2, y2)<<'\n';
    }
}