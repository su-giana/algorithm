#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
vector<int> board(101, 0);
set<pair<int, int> > s;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int solve()
{
    queue<int> q;
    q.push(1);
    int cnt = 0;

    while(!q.empty())
    {
        int q_size = q.size();
        while(q_size--)
        {
            int cur = q.front();
            q.pop();

            for(int i = 1 ; i<=6 ; i++)
            {
                int next = cur + i;

                if(next == 100)
                {
                    return cnt+1;
                }
                else if(next>100)
                    continue;

                if(s.find(make_pair(cur, i))==s.end())
                {
                    next = board[next] == 0 ? next : board[next];

                    q.push(next);
                    s.insert(make_pair(cur, i));
                }
            }
        }
        cnt++;
    }
    return cnt;
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n+m ; i++)
    {
        int a, b;
        cin>>a>>b;

        board[a] = b;
    }

    cout<<solve();
}