#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* class Solution {
public:
    vector<int> answer;
    void validPath(int cur, vector<vector<int> >& connections, int previous)
    {
        previous |= (1<<cur);
        bool stop = true;
        for(int i = 0 ; i<connections[cur].size() ; i++)
        {
            if(previous & (1<<connections[cur][i]))
            {
                answer.push_back(-1);
                return;
            }
            stop = false;
            validPath(connections[cur][i], connections, previous);
        }

        if(stop)    answer.push_back(previous);
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int> > connections(colors.size(), vector<int>());
        for(int i = 0 ; i<edges.size() ; i++)
        {
            connections[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i = 0 ; i <colors.size() ; i++)
        {
            validPath(i, connections, 0);
        }

        if(answer[answer.size()-1] == -1)    return -1;

        int maxCount = 0;

        for(int i = 0 ; i<answer.size() ; i++)
            cout<<bitset<8>(answer[i])<<" ";
        cout<<endl;

        for(int i = 0 ; i<answer.size() ; i++)
        {
            vector<int> alpha(26, 0);
            for(int j = 0 ; j<colors.size() ; j++)
            {
                if(answer[i] & (1<<j))
                    alpha[colors[j] - 'a']++;
            }
            maxCount = max(maxCount, *max_element(alpha.begin(), alpha.end()));
        }
        

        return maxCount;
    }
}; */

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        int k = 26;
        vector<vector<int> > graph(n, vector<int>());
        vector<int> indegree(n, 0);

        for(int i = 0 ; i<edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        unordered_set<int> zero_indegree;
        for(int i = 0 ; i<n ; i++)
        {
            if(indegree[i] == 0)
            zero_indegree.insert(i);
        }

        vector<vector<int> > count(n, vector<int>(k, 0));
        for(int i = 0 ; i<n ; i++)
        {
            count[i][colors[i] - 'a']++;
        }

        int max_count = 0;
        int visited = 0;

        while(!zero_indegree.empty())
        {
            int u = *zero_indegree.begin();
            zero_indegree.erase(u);
            visited++;
            for(int v : graph[u])
            {
                for(int i = 0; i<k ; i++)
                {
                    count[v][i] = max(count[v][i], count[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    zero_indegree.insert(v);
                }
               
            }
            max_count = max(max_count, *max_element(count[u].begin(), count[u].end()));
        }

        return visited == n ? max_count : -1;
    }
};