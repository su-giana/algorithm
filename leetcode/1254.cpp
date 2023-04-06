#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> >& grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        if((i>=n || j>=m || i< 0 || j<0) || grid[i][j] != 0)
            return;

        grid[i][j] = 1;
        
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        for(int k = 0 ; k<4 ; k++)
        {
            dfs(grid, i+dx[k], j+dy[k]);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int answer = 0;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if((i*j==0 || i==n-1 || j==m-1) && grid[i][j]==0)
                {
                    dfs(grid, i, j);
                }   
            }
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }

        for(int i = 1 ; i<n-1 ; i++)
        {
            for(int j = 1 ; j<m-1 ; j++)
            {
                if(grid[i][j] == 0)
                {
                    dfs(grid, i, j);
                    answer++;
                }
            }
        }

        return answer;
    }
};