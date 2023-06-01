#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<long long, long long> > circles;

bool compare(pair<long long, long long>& a, pair<long long, long long>& b)
{
    if(a.first != b.first)  return a.first < b.first;
    return (a.second - a.first) > (b.second - b.first);
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long solution()
{
    sort(circles.begin(), circles.end(), compare);
    int n = circles.size();
    long long ans = 1+n;

    pair<long long, long long> cur = circles[0];
    for(int i = 1 ; i<n ; i++)
    {
        pair<long long, long long> next = circles[i];
        if(cur.first == next.first && cur.second == next.second)
        {
            ans++;
            continue;
        }
        else if(cur.first >= next.second)
        {
            cur.first = next.first;
            cur.second = min(cur.second, next.second);
        }
        else if(cur.first < next.second)
        {
            cur.first = next.first;
            cur.second = next.second;
        }
    }

    return ans;
}

int main()
{
    init();

    int n;
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int x, r;
        cin>>x>>r;

        circles.push_back(make_pair(x+r, x-r));
    }
    cout<<solution();
}