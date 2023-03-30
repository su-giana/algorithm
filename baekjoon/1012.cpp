#include <iostream>
#include <vector>

using namespace std;


int dfs(vector<vector<int> >& map, vector<vector<bool> >& visited, int m, int n, int order, bool infarm)
{
    if(visited[m][n])  return order;

    visited[m][n] = true;

    if(!map[m][n])
    {
        return max({dfs(map, visited, m+1, n, order, false), dfs(map, visited, m-1, n, order, false), dfs(map, visited, m, n+1, order, false), dfs(map, visited, m, n-1, order, false)});
        
    }
    
    else                    
    {
        if(infarm)
        {
            return max({dfs(map, visited, m+1, n, order, true), dfs(map, visited, m-1, n, order, true), dfs(map, visited, m, n+1, order, true), dfs(map, visited, m, n-1, order, true)});
        }
        else
        {
            return max({dfs(map, visited, m+1, n, order+1, true), dfs(map, visited, m-1, n, order+1, true), dfs(map, visited, m, n+1, order+1, true), dfs(map, visited, m, n-1, order+1, true)});
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int test = 0 ; test<t ;  test++)
    {
        int n, m, k;
        cin>>m>>n>>k;

        vector<vector<int> > map(m, vector<int>(n, 0));
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0 ; i<m ; i++)
        {
            int h, v;
            cin>>h>>v;
            map[h][v] = 1;
        }

        int needed = dfs(map, visited, 0, 0, 0, false);
    }
}