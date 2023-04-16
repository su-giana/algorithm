#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.first<b.first;
}

int main()
{
    int m;
    cin>>m;
    set<pair<int, int> > lines;
    vector<pair<int, int> > cables;
    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        lines.insert(make_pair(a, b));
    }

    for(auto iter = lines.begin() ; iter != lines.end() ; iter++)
    {
        cables.push_back(*iter);
    }
    sort(cables.begin(), cables.end(), compare);

    int n = cables.size();
    int overlapped = m - n;
    vector<vector<int> > dp(n+1, vector<int>(3, 0));
    for(int i = 0 ; i<n ; i++)
    {
        dp[i][0] = cables[i].second;
        dp[i][1] = cables[i].first;
    }
    
    int biggest = INT_MAX;
    for(int i = n-1 ; i>=0 ; i--)
    {
        int cable = dp[i][0];
        int denominator = dp[i][1];
        if(cable>=biggest)  {dp[i][2] = dp[i+1][2]; continue;}
        int consume = 0;
        for(int j = 0 ; j<i ; j++)
        {
            if(dp[j][0]>cable && dp[j][0]<biggest)
            {
                consume++;
            }
        }
        if(dp[i][1] == dp[i+1][1] && dp[i+1][0] != -1)  
        { 
            biggest = dp[i][0];
            dp[i][0] = -1;
            continue;
        }
        else if(dp[i][1]==dp[i+1][1] && dp[i+1][0] == -1)
        {
            dp[i][0] = -1;
            dp[i][1] = dp[i+1][1] + 1;
            continue;
        }

        int maxIndex = max_element(dp.begin(), dp.begin() + i) - dp.begin(), loss=0;
        for(int j = maxIndex+1 ; j<=i ; j++)   
        {
            if(dp[j]<dp[maxIndex])  loss++;
        }

        // add this cable
        if(consume<=loss)
        {
            biggest = dp[i][0];
            dp[i][2] = dp[i+1][2]+consume;   
        }
        // left this cable
        else
        {
            dp[i][0] = 0;
            dp[i][2] = dp[i+1][2] + 1;
        }

        for(int j = 0 ;j<dp.size() ; j++)
            cout<<dp[j][0]<<" "<<dp[j][1]<<" "<<dp[j][2]<<endl;
        cout<<endl;
    }

    cout<<dp[0][2]+overlapped;
}