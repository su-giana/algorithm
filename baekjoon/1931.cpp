#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second)    return a.first<b.first;
    return a.second<b.second;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n;
    cin>>n;
    
    vector<pair<int, int> > schedules(n);

    for(int i = 0 ; i<n ; i++)
    {
        int start, end;
        cin>>start>>end;
        schedules[i] = (make_pair(start, end));
    }
    sort(schedules.begin(), schedules.end(), compare);

    vector<pair<int, int> > que;
    for(int i = 0 ; i<n ; i++)
    {
        if(que.empty()) { que.push_back(schedules[i]); continue; }

        int m = que.size()-1;
        if(que[m].second <= schedules[i].first)
        {
            que.push_back(schedules[i]);
        }
    }
    
    cout<<que.size();
}