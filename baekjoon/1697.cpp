#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getMaxTime(int n, int k)
{
    queue<pair<int, int> > que;
    que.push(make_pair(n, 0));
    int maxTime = INT_MAX;
    vector<bool> visited(100001, false);
    visited[n] = true;

    while(!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        if(cur.first == k)  maxTime = min(maxTime, cur.second);
        if(cur.second >= maxTime)   continue;

        if(2*cur.first<100001 && !visited[2*cur.first])   
        {
            que.push(make_pair(2*cur.first, cur.second+1));
            visited[2*cur.first] = true;
        }

        if(cur.first+1<100001 && !visited[cur.first+1])   
        {
            que.push(make_pair(cur.first+1, cur.second+1));
            visited[cur.first+1] = true;
        }

        if(cur.first-1>=0 && !visited[cur.first-1])   
        {
            que.push(make_pair(cur.first-1, cur.second+1));
            visited[cur.first-1] = true;
        }
    }

    return maxTime;
}

int main()
{
    init();

    int n, k;
    cin>>n>>k;

    cout<<getMaxTime(n, k);
}