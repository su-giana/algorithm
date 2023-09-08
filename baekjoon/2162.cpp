#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > lines(3000, vector<int>());

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n;
    
    for(int i = 0 ; i<n ; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        lines.push_back({x1, y1, x2, y2});
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(i==j)    continue;

            
        }
    }
}