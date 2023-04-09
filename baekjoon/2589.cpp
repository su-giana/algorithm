#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int r = 0, c = 0;
int temp = 0;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int dfs(vector<vector<int> >& map, int i, int j)
{
    int n = map.size(), m = map[0].size();
    if((i<0 || i>=n || j<0 || j>=m) || map[i][j] == -1)    return -1;
    if(map[i][j] != INT_MAX)    return map[i][j];

    for(int k = 0 ; k<4 ; k++)
    {
        if(!(i<=0 || j<=0 || i >= n-1 || j>=m-1) && map[i+dx[k]][j+dy[k]] != -1 && map[i+dx[k]][j+dy[k]] != INT_MAX)
            map[i][j] = min(map[i][j], map[i+dx[k]][j+dy[k]]);
    }
    if(map[i][j] != INT_MAX)
    {
        map[i][j] += 1;
    }
    else
    {
        map[i][j] = -2;
    }

    for(int k = 0 ; k<4 ; k++)
    {
        int ti = i+dx[k], tj = j + dy[k];
        if(dfs(map, ti, tj)>=0)
        {
            if(map[i][j] == -2) map[i][j] = map[ti][tj]+1;
            map[i][j] = min(map[i][j], map[ti][tj]+1);
        }

    } 

    for(int k = 0 ; k<map.size() ; k++)
    {
        for(int l = 0 ; l<map[0].size() ; l++)
            cout<<map[k][l]<<" ";
        cout<<endl;
    }

    if(map[i][j] == -2) {map[i][j] = 0; return 0;}
    return map[i][j];
}

int main()
{
    cin>>n>>m;
    vector<vector<int> > map(n, vector<int>(m, -1));

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            if(s[j] == 'L')
                map[i][j] = INT_MAX;
        }
    }

    int answer = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(map[i][j] == INT_MAX)
            {
                dfs(map, i, j);
            }
            
        }
    } 

    for(int i = 0 ; i<n ; i++)
    {
        answer = max(answer, *max_element(map[i].begin(), map[i].end()));
    }

    cout<<answer;
}