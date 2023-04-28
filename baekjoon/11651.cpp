#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<pair<int, int> > spots;
    for(int i = 0 ; i<n ; i++)
    {
        int x, y;
        cin>>x>>y;

        spots.push_back(make_pair(x, y));
    }

    sort(spots.begin(), spots.end(), compare);

    for(int i = 0 ; i<n ; i++)
    {
        cout<<spots[i].first<<" "<<spots[i].second<<'\n';
    }
}