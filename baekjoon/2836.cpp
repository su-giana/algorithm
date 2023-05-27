#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<long long, long long> > taxis;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long solution()
{
    int n = taxis.size();
    long long ans = 0;

    pair<long long, long long> section = taxis[0];
    for(int i = 1 ; i<n ; i++)
    {
        if(section.second < taxis[i].first)
        {
            ans += (section.second - section.first)*2;
            section.first = taxis[i].first;
            section.second = taxis[i].second;
        }
        else
        {
            section.second = max(section.second, taxis[i].second);
        }
    }

    ans += (section.second - section.first) * 2;
    return ans;
}

int main()
{
    init();

    int n, m;
    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)
    {
        long long a, b;
        cin>>a>>b;
        if(a>b)
            taxis.push_back(make_pair(b, a));
    }

    sort(taxis.begin(), taxis.end());

    cout<<(m + solution());
}