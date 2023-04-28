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

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<pair<int, string> > spots;
    for(int i = 0 ; i<n ; i++)
    {
        int x;
        string y;
        cin>>x>>y;

        spots.push_back(make_pair(x, y));
    }

    sort(spots.begin(), spots.end(), compare);

    for(int i = 0 ; i<n ; i++)
    {
        cout<<spots[i].first<<" "<<spots[i].second<<'\n';
    }
}