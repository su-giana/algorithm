#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        priority_queue<int> q_max;
        priority_queue<int, vector<int>, greater<int> > q_min;
        unordered_map<int, int> map;

        while(n--)
        {
            
            char cmd;
            cin>>cmd;
            int val;
            cin>>val;

            if(cmd == 'I')
            {
                if(map.find(val) == map.end())
                {
                    map.insert(make_pair(val, 1));
                }
                else
                {
                    map[val]++;
                }
                q_max.push(val);
                q_min.push(val);
            }
            else if(val == 1)
            {
                while(!q_max.empty())
                {
                    int val_ = q_max.top();
                    q_max.pop();
                    if(map[val_]>0)
                    {
                        map[val_]--;
                        break;
                    }
                }
            }
            else
            {
                while(!q_min.empty())
                {
                    int val_ = q_min.top();
                    q_min.pop();
                    if(map[val_]>0)
                    {
                        map[val_]--;
                        break;
                    }
                }
            }
        }

        int maxi = INT_MIN, mini = INT_MAX;
        bool isEmpty = true;
        while(!q_max.empty())
        {
            int val_ = q_max.top();
            if(map[val_]>0)
            {
                isEmpty = false;
                maxi = max(maxi, val_);
                mini = min(mini, val_);
            }
            q_max.pop();
        }

        if(isEmpty)
        {
            cout<<"EMPTY"<<'\n';
        }
        else
        {
            cout<<maxi<<' '<<mini<<'\n';
        }
    }
}