#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getMin(vector<vector<int> >& map, int start, int cur, long long cost, vector<bool> visited)
{
    int n = map.size();
    if(start == cur)
    {
        if(accumulate(visited.begin(), visited.end(), 0) != n)  return INT_MAX;
        return cost;
    }
    
    long long minCost = INT_MAX;
    
    if(cur==-1) cur = start;

    for(int i = 0 ; i<n ; i++)
    {
        if(map[cur][i]!=0 && !visited[i])
        {
            visited[i] = true;
            minCost = min(minCost, getMin(map, start, i, cost + map[cur][i], visited));
            visited[i] = false;
        }
    }

    return minCost;
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<vector<int> > map(n, vector<int>(n, 0));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            int cost;
            cin>>cost;
            map[i][j] = cost;
        }
    }

    long long minPath = INT_MAX;
    for(int i = 0 ; i<n ; i++)
    {
        minPath = min(minPath, getMin(map, i, -1, 0, vector<bool>(n,false)));
    }

    cout<<minPath;
}