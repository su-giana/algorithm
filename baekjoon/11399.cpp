#include <iostream>
#include <vector>
#include <algorithm>

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

    int n;
    cin>>n;

    vector<int> times;
    for(int i = 0 ; i<n ; i++)
    {
        int time;
        cin>>time;
        times.push_back(time);
    }

    sort(times.begin(), times.end());
    for(int i = 0 ; i<n-1 ; i++)
    {
        times[i+1] = times[i] + times[i+1];
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
        ans += times[i];

    cout<<ans;
}