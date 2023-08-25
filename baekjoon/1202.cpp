#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<pair<int, int> > gems;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct compare
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

bool compare2(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first)  return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    init();

    priority_queue<int, vector<int>, greater<int> > q_bag;
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> q_gem;

    cin>>n>>k;

    for(int i = 0 ; i<n ; i++)
    {
        int m, v;
        cin>>m>>v;
        gems.push_back(make_pair(m, v));
    }

    for(int i = 0 ; i<k ; i++)
    {
        int bag;
        cin>>bag;
        q_bag.push(bag);
    }

    sort(gems.begin(), gems.end(), compare2);

    int index = 0;
    long long ans = 0;
    while(!q_bag.empty())
    {
        int now = q_bag.top();
        q_bag.pop();

        while(index < n && gems[index].first <= now)
        {
            q_gem.push(gems[index]);
            index++;
        }

        if(q_gem.empty())   continue;

        ans += q_gem.top().second;
        q_gem.pop();
    }

    cout<<ans;
}