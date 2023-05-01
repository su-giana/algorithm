#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getParent(int vertex, vector<int>& check)
    {
        if(check[vertex] == vertex)     return vertex;
        return getParent(check[vertex], check);
    }

    void unionParent(int vertex1, int vertex2, vector<int>& check)
    {
        vertex1 = getParent(vertex1, check);
        vertex2 = getParent(vertex2, check);
        if(vertex1 < vertex2)   check[vertex2] = vertex1;
        else                    check[vertex1] = vertex2;
    }

    bool isCycle(int vertex1, int vertex2, vector<int>& check)
    {
        vertex1 = getParent(vertex1, check);
        vertex2 = getParent(vertex2, check);
        if(vertex1 == vertex2)  return true;
        return false;
    }

    int prim(vector<vector<int> >& edges, vector<int>& check)
    {
        int m = edges.size();
        int ans = 0;

        for(int i = 0 ; i<m ; i++)
        {
            if(!isCycle(edges[i][1], edges[i][2], check))
            {
                unionParent(edges[i][1], edges[i][2], check);
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }

    bool sameGraph(int n, vector<int>& check)
    {
        vector<int> temp(n+1, 1);
        for(int i = 1 ; i<=n ; i++)
        {
            temp[i] = getParent(i, check);
        }
        
        for(int i = 1 ; i<n ; i++)
        {
            if(temp[i] != temp[i+1])
                return false;
        }
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        vector<vector<int> > comPath;
        vector<vector<int> > alicePath;
        vector<vector<int> > bobPath;
        vector<int> check(n+1, 0);

        for(int i = 0 ; i<=n ; i++)
            check[i] = i;

        for(int i = 0 ; i<m ; i++)
        {
            if(edges[i][0] == 1)    alicePath.push_back(edges[i]);
            if(edges[i][0] == 2)    bobPath.push_back(edges[i]);
            if(edges[i][0] == 3)    comPath.push_back(edges[i]);
        }    

        int ans = 0;

        ans += prim(comPath, check);
        if(sameGraph(n, check))     return ans + alicePath.size() + bobPath.size();
        

        vector<int> checkA = check;
        ans += prim(alicePath, checkA);
        if(!sameGraph(n, checkA))   return -1;

        vector<int> checkB = check;
        ans += prim(bobPath, checkB);
        if(!sameGraph(n, checkB))   return -1;

        return ans;
    }
};