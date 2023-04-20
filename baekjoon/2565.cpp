#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first<b.first;
}

int main()
{
    int m;
    vector<pair<int, int> > lines;
    
    cin>>m;
    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        lines.push_back(make_pair(a,b));
    }

    sort(lines.begin(), lines.end(), compare);
    vector<int> dp(m, 0);

    for(int i = 0 ; i<m ; i++)
    {
       dp[i] = 1;
        for(int j = 0 ; j<i ; j++)
        {
            if(lines[i].second>lines[j].second)
                dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    cout<< m - *max_element(dp.begin(), dp.end());
}