#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void floyd(vector<vector<int> >& graph, vector<vector<int> >& maxLen)
    {
        int n = graph.size();
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                for(int k = 0 ; k<n ; k++)
                {
                    if(graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                        maxLen[i][j] = max(maxLen[i][k], maxLen[k][j]);
                    }
                }
            }
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        int m = edgeList.size();
        vector<vector<int> > graph(n, vector<int>(n, 1000000001));
        for(int i = 0 ; i<m ; i++)
        {
            int in = min(edgeList[i][0], edgeList[i][1]);
            int out = max(edgeList[i][0], edgeList[i][1]);
            int val = edgeList[i][2];

            graph[in][out] = min(graph[in][out], val);
            graph[out][in] = min(graph[out][in], val);
        }

        for(int i = 0 ; i<n ; i++)
        {
            graph[i][i] = 0;
        }

        vector<vector<int> > maxLen = graph;
        floyd(graph, maxLen);

        int q = queries.size();
        vector<bool> ans(q, false);
        for(int i = 0 ; i<q ; i++)
        {
            int in = queries[i][0];
            int out = queries[i][1];
            int limit = queries[i][2];
            if(maxLen[in][out]<limit)
                ans[i] = true;
        }

        return ans;
    }
};