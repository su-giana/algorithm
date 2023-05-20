#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void getCnt(vector<int>& elevator, int s, int u, int d)
{
    int n = elevator.size();
    deque<int> q;
    q.push_back(s);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();

        if(cur+u>=n)    {}
        else if(elevator[cur+u]==-1 || elevator[cur+u] > elevator[cur] + 1)
        {
            elevator[cur+u] = elevator[cur] + 1;
            q.push_back(cur+u);
        }

        if(cur-d<=0)    continue;
        if(elevator[cur-d] == -1 || elevator[cur-d] > elevator[cur] + 1)
        {
            elevator[cur-d] = elevator[cur] + 1;
            q.push_back(cur-d);
        }
    }
}

int main()
{
    init();

    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;

    vector<int> elevator(f+1, -1);
    elevator[s] = 0;

    getCnt(elevator, s, u, d);
    if(elevator[g] == -1)   cout<<"use the stairs";
    else                    cout<<elevator[g];
}