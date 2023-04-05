#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int dfs(vector<vector<bool> > map, int i, int j, int count)
{
    if(n == 0 || m == 0) return count-1;
    if(i>=n || i<0 || j>=m || j<0)    return count-1;    
    if(map[i][j])                     return count-1;
    
    
    map[i][j] = true;
    return max(max(dfs(map, i+1, j, count+1), dfs(map, i-1, j, count+1)), max(dfs(map, i, j-1, count+1), dfs(map, i, j+1, count+1)));
}

int main()
{
    cin>>n>>m;
    vector<vector<bool> > map(n, vector<bool>(m, false));

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            if(s[j] == 'W')
                map[i][j] = true;
            else
                map[i][j] = false;
        }
    }

    int max_el = 0;
    
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            
            max_el = max(max_el, dfs(map, i, j, 0));
        }
    } 

    cout<<max_el;
}