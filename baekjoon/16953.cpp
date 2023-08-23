#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

long long a, b;
set<long long> s;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs()
{
    queue<long long> q;
    q.push(a);
    s.insert(a);

    int cnt = 0;
    while(!q.empty())
    {
        int q_size = q.size();
        for(int k = 0 ; k<q_size ; k++)
        {
            long long cur = q.front();
            q.pop();

            if(cur == b)    return cnt+1;

            if(cur*2 <= 1000000000ll && s.find(cur*2) == s.end())
            {
                q.push(cur*2);
                s.insert(cur*2);
            }
            if(cur*10+1 <= 1000000000ll && s.find(cur*10+1) == s.end())
            {
                q.push(cur*10 + 1);
                s.insert(cur*10 + 1);
            }
        }
        cnt++;
    }

    return -1;
}

int main()
{
    init();

    cin>>a>>b;

    cout<<bfs();
}