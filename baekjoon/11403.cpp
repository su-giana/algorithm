#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map(100, vector<int>(100 ,0));

void init()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main()
{
    init();

    int n;
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int k = 0 ; k<n ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {

                if(map[i][k] && map[k][j])
                {
                    map[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
}