#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        if(a[1] == b[1])	return a[0]>b[0];
        return a[1]>b[1];
    }
};

void dfs(int cur, vector<vector<vector<int>>>& paths, vector<bool>& visited, vector<int>& summits, int intensity, priority_queue<vector<int>, vector<vector<int>>, compare>& q)
{
    if(find(summits.begin(), summits.end(), cur) != summits.end())
    {
        vector<int> temp = {cur, intensity};
        q.push(temp);
        return;
    }
    visited[cur] = true;
    
    int n = paths[cur].size();
    for(int i = 0 ; i<n ; i++)
    {
        if(!visited[paths[cur][i][0]])
        {
            dfs(paths[cur][i][0], paths, visited, summits, max(intensity, paths[cur][i][1]), q);
        }
    }
    
    visited[cur] = false;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    vector<vector<vector<int> > > map(n+1, vector<vector<int> >());
    priority_queue<vector<int>, vector<vector<int>>, compare> que;
    int m =paths.size();
    for(int i = 0 ; i<m ; i++)
    {
        map[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        map[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    
    int t = gates.size();
    
    for(int i = 0 ; i<t ; i++)
    {
        vector<bool> visited(n+1, false);
        dfs(gates[i], map, visited, summits, 0, que);
    }

    return que.top();
}