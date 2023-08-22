#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, pair<int, int> > map;

int n, k;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs()
{
    if(n==k)
    {
        cout<<0<<'\n'<<1;
        return;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    map.insert(make_pair(n, make_pair(0, 1)));

    while(!q.empty())
    {
        int cur = q.front().first;
        int tried = q.front().second;
        q.pop();

        if(cur*2 <= 100000)
        {
            if(map.find(cur*2) == map.end())
            {
                q.push(make_pair(cur*2, tried+1));
                map.insert(make_pair(cur*2, make_pair(tried+1, 1)));
            }
            else if(map[cur*2].first > tried+1)
            {
                q.push(make_pair(cur*2, tried+1));
                map[cur*2].first = tried+1;
                map[cur*2].second = 1;
            }
            else if(map[cur*2].first == tried+1)
            {
                q.push(make_pair(cur*2, tried+1));
                map[cur*2].second++;
            }
        }
        if(cur+1 <= 100000)
        {
            if(map.find(cur+1) == map.end())
            {
                q.push(make_pair(cur+1, tried+1));
                map.insert(make_pair(cur+1, make_pair(tried+1, 1)));
            }
            else if(map[cur+1].first > tried+1)
            {
                q.push(make_pair(cur+1, tried+1));
                map[cur+1].first = tried+1;
                map[cur+1].second = 1;
            }
            else if(map[cur+1].first == tried+1)
            {
                q.push(make_pair(cur+1, tried+1));
                map[cur+1].second++;
            }
        }
        if(cur-1 >= 0)
        {
            if(map.find(cur-1) == map.end())
            {
                q.push(make_pair(cur-1, tried+1));
                map.insert(make_pair(cur-1, make_pair(tried+1, 1)));
            }
            else if(map[cur-1].first > tried+1)
            {
                q.push(make_pair(cur-1, tried+1));
                map[cur-1].first = tried+1;
                map[cur-1].second = 1;
            }
            else if(map[cur-1].first == tried+1)
            {
                q.push(make_pair(cur-1, tried+1));
                map[cur-1].second++;
            }
        }
    }

    cout<<map[k].first<<'\n'<<map[k].second;
}

int main()
{
    init();

    cin>>n>>k;

    bfs();
}