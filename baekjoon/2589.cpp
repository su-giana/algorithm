#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int getMax(vector<vector<int> >& map, vector<vector<bool> >& visited, int i, int j)
{
    int n = map.size(), m = map[0].size();
    if((i<0 || i>=n || j<0 || j>=m) || map[i][j] == -1)    return -1;
    if(visited[i][j])   return map[i][j];

    int temp = map[i][j];
    visited[i][j] = true;
    for(int k = 0 ; k<4 ; k++)
    {
        int ti = i+dx[k], tj = j + dy[k];
        temp = max(temp, getMax(map, visited, ti, tj));
    }
    
    return temp;
}

void dfs(vector<vector<int> >& map, int i, int j, int count)
{
    int n = map.size(), m = map[0].size();
    if((i<0 || i>=n || j<0 || j>=m) || map[i][j] <= count)    return;

    map[i][j] = count;

    for(int k = 0 ; k<4 ; k++)
    {
        int ti = i+dx[k], tj = j + dy[k];
        dfs(map, ti, tj, count+1);
    }
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
    vector<vector<int> > copied(n, vector<int>(m));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            
            if(map[i][j] != -1)
            {
                copy(map.begin(), map.end(), copied.begin());
                dfs(copied, i, j, 1);
            }
            
            vector<vector<bool> > visited(n, vector<bool>(m, false));
            answer = max(answer, getMax(copied, visited, i, j)-1);
        }
    } 

    cout<<answer;
}