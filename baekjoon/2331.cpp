#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int dfs(vector<vector<long long> >& vertices, vector<bool>& visited, vector<long long> check, int a,  int p)
{
    if(visited[a])
    {
        return check[a];
    }
    visited[a] = true;

    int temp = a;
    int next = 0;
    while(temp != 0)
    {
        next += pow((temp%10), p);
        temp /= 10;
    }
    if(visited[next])   return check[next];
    vertices[a].push_back(next);
    check[next] = check[a] + 1;

    return dfs(vertices, visited, check, next, p);
}

int main()
{

    int a, p;
    cin>>a>>p;

    vector<vector<long long> > vertices(250000, vector<long long>());
    vector<bool> visited(250000, false);
    vector<long long> check(250000, 0);

    cout<<dfs(vertices, visited, check, a, p);
}