#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;
unordered_map<int, int> s;

int n, k;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    s.insert(make_pair(n, 0));
    int ans = INT_MAX;

    while(!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if(cur == k)    ans = min(ans, time);

        if(2*cur <= 100000 && (s.find(2*cur) == s.end() || s[2*cur] > time))
        {
            
            q.push(make_pair(2*cur, time));
            if(s.find(2*cur) == s.end())    s.insert(make_pair(2*cur, time));
            else    s[2*cur] = time;
        }
        if(cur+1 <= 100000 && (s.find(cur+1) == s.end() || s[cur+1] > time+1))
        {
            q.push(make_pair(cur+1, time+1));
            if(s.find(cur+1) == s.end())    s.insert(make_pair(cur+1, time+1));
            else    s[cur+1] = time+1;
        }
        if(cur - 1 >=0 && (s.find(cur-1) == s.end() || s[cur-1] > time+1))
        {
            q.push(make_pair(cur-1, time+1));
            if(s.find(cur-1) == s.end())    s.insert(make_pair(cur-1, time+1));
            else    s[cur-1] = time+1;
        }
    }

    return ans;
}

int main()
{
    init();

    cin>>n>>k;

    cout<<bfs();
}