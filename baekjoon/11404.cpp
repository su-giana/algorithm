#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<vector<long long> > map(100, vector<long long>(100, 10000000001ll));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>m;
    
    for(int i = 0 ; i<m ; i++)
    {
        long long s, e, c;
        cin>>s>>e>>c;
        map[s-1][e-1] = min(c, map[s-1][e-1]);
    }

    for(int i = 0 ; i<n ; i++)
    {
        map[i][i] = 0;
    }

    for(int k = 0 ; k<n ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            if(k==i)    continue;
            for(int j = 0 ; j<n ; j++)
            {
                if(j==i || j==k)    continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(map[i][j]==10000000001ll)
            {
                cout<<0<<" ";
            }
            else
            {
                cout<<map[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
}