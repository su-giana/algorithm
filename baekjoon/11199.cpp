#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;

    priority_queue<pair<int, int>, vector<pair<int, int> > > que;

    for(int i = 0 ; i<n ; i++)
    {
        int ci, ti;
        cin>>ci>>ti;
        que.push(make_pair(ci, ti));
    }

    vector<bool> occupied(t, false);
    int cnt = 0;
    long long balance = 0;
    while(!que.empty() && cnt<t)
    {
        pair<int, int> cur = que.top();
        que.pop();

        if(!occupied[cur.second])
        {
            occupied[cur.second] = true;
            cnt++;
            balance += cur.first;
        }
        else
        {
            for(int i = cur.second - 1 ; i>=0 ; i--)
            {
                if(!occupied[i])
                {
                    occupied[i] = true;
                    cnt++;
                    balance += cur.first;
                    break;
                }
            }
        }
    }

    cout<<balance;
}