#include <iostream>
#include <vector>

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