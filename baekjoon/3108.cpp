#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <set>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool isOverlapped(vector<vector<bool> >& layer1, vector<vector<bool> >& layer2)
{
    for(int i = 0 ; i<1001 ; i++)
    {
        for(int j = 0 ; j<1001 ; j++)
        {
            if(layer1[i][j] && layer2[i][j])
                return true;
        }
    }
    return false;
}

void getMinPenUp(vector<vector<vector<bool> > >& dots, vector<int>& visited)
{
    int n = dots.size();
    int m = visited.size();
    
    for(int i = 0 ; i<n-1 ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            if(visited[i] != visited[j] && isOverlapped(dots[i], dots[j]))
            {
                int root = min(visited[i], visited[j]);
                int changed = max(visited[i], visited[j]);

                for(int k = 0 ; k<m ; k++)
                {
                    if(visited[k] == changed)
                        visited[k] = root;
                }
            }
        }
    }
}

void drawSquare(vector<vector<bool> >& square, int x1, int y1, int x2, int y2)
{
    for(int i = x1+500 ; i<=x2+500 ; i++)
    {
        square[i][y1+500] = true;
        square[i][y2+500] = true;
    }
    for(int i = y1+500 ; i<=y2+500 ; i++)
    {
        square[x1+500][i] = true;
        square[x2+500][i] = true;
    }
}

int getRootCnt(vector<int>& visited)
{
    int n = visited.size();
    vector<int> roots(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int root = i;
        while(root != visited[root])
        {
            root = visited[root];
        }
        roots[i] = root;
    }

    set<int> cnt(roots.begin(), roots.end());
    return cnt.size()-1;
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<vector<bool> > > dots;
    vector<vector<bool> > temp(1001, vector<bool>(1001, false));
    temp[500][500] = true;
    dots.push_back(temp);

    for(int i = 0 ; i<n ; ++i)
    {
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        vector<vector<bool> > square(1001, vector<bool>(1001, false));
        drawSquare(square, x1, y1, x2, y2);
        dots.push_back(square);
    }

    vector<int> visited(n+1, 0);
    for(int i = 0 ; i<=n ; i++)
    {
        visited[i] = i;
    }

    getMinPenUp(dots, visited);
    cout<<getRootCnt(visited);
}