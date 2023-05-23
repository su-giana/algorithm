#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool compare(pair<long long, long long>& a, pair<long long, long long>& b)
{
    if(a.first!=b.first)    return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    init();

    int n;
    cin>>n;
    
    vector<pair<long long, long long> > lines;
    for(int i = 0 ; i<n ; i++)
    {
        long long x, y;
        cin>>x>>y;

        lines.push_back(make_pair(x, y));
    }
    sort(lines.begin(), lines.end(), compare);

    long long ans = 0;
    while(lines.size()>1)
    {
        pair<long long, long long> front = lines.back();
        lines.pop_back();
        pair<long long, long long> back = lines.back();
        lines.pop_back();

        if(back.first <= front.second)
        {
            if(front.second >= back.second) lines.push_back(front);
            else if(front.second < back.second)
            {
                front.second = back.second;
                lines.push_back(front);
            }
        }
        else
        {
            ans+=front.second - front.first;
            lines.push_back(back);
        }
    }
    ans += lines.back().second - lines.back().first;

    cout<<ans;
}