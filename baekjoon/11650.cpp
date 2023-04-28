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

int main()
{
    int n;
    cin>>n;

    vector<pair<int, int> > spots;
    for(int i = 0 ; i<n ; i++)
    {
        int x, y;
        cin>>x>>y;

        spots.push_back(make_pair(x, y));
    }

    sort(spots.begin(), spots.end());

    for(int i = 0 ; i<n ; i++)
    {
        cout<<spots[i].first<<" "<<spots[i].second<<endl;
    }
}