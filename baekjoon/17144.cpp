#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int> > map(50, vector<int>(50, 0));
pair<int, int> upper = make_pair(-1, -1);
pair<int, int> lower = make_pair(-1, -1);
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int n, m, t;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void disperse()
{
    vector<vector<int> > original = map;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(original[i][j] != 0 && original[i][j] != -1)
            {
                int value = original[i][j] / 5;
                for(int k = 0 ; k<4 ; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if(tx < 0 || ty < 0 || tx>=n || ty >= m || original[tx][ty] == -1)
                        continue;
                    
                    map[tx][ty] += value;
                    map[i][j] -= value;
                }
            }
        }
    }
}

void circulateUpper(vector<vector<int> >& original)
{
    for(int i = 0 ; i<m-1 ; i++)
    {
        map[upper.first][i+1] = original[upper.first][i];
    }
    for(int i = 1 ; i<=upper.first ; i++)
    {
        map[i-1][m-1] = original[i][m-1];
    }
    for(int i = 1 ; i<m ; i++)
    {
        map[0][i-1] = original[0][i];
    }
    for(int i = 0 ; i < upper.first ; i++)
    {
        map[i+1][0] = original[i][0];
    }

    map[upper.first][upper.second] = -1;
    if(upper.second == m-1)
    {
        map[upper.first-1][upper.second] = 0;
    }
    else
    {
        map[upper.first][upper.second+1] = 0;
    }
}

void circulateLower(vector<vector<int> >& original)
{
    for(int i = 0 ; i<m-1 ; i++)
    {
        map[lower.first][i+1] = original[lower.first][i];
    }
    for(int i = lower.first ; i<n-1 ; i++)
    {
        map[i+1][m-1] = original[i][m-1];
    }
    for(int i = 1 ; i<m ; i++)
    {
        map[n-1][i-1] = original[n-1][i];
    }
    for(int i = lower.first+1 ; i < n ; i++)
    {
        map[i-1][0] = original[i][0];
    }

    map[lower.first][lower.second] = -1;
    if(lower.second == m-1)
    {
        map[lower.first+1][lower.second] = 0;
    }
    else
    {
        map[lower.first][lower.second+1] = 0;
    }
}


void circulator()
{
    vector<vector<int> > original = map;

    circulateUpper(original);

    circulateLower(original);
}

int main()
{
    init();

    cin>>n>>m>>t;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int val;
            cin>>val;
            map[i][j] = val;

            if(val == -1 && upper.first == -1)
            {
                upper.first = i;
                upper.second = j;
            }
            else if(val == -1 && upper.first != -1)
            {
                lower.first = i;
                lower.second = j;
            }
        }
    }

    while(t--)
    {
        disperse();


        circulator();
    }

    

    long long answer = 0;
    for(int i = 0 ; i<n ; i++)
    {
        answer += accumulate(map[i].begin(), map[i].end(), 0);
    }
    answer += 2;

    cout<<answer;
}