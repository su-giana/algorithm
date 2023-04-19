#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first<b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}


int main()
{
    int m;
    vector<pair<int, int> > lines;
    set<int> visited;
    set<pair<int, int> > cables;
    cin>>m;
    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin>>a>>b;

        cables.insert(make_pair(a,b));
    }

    for(set<pair<int, int> >::iterator iter = cables.begin() ; iter != cables.end() ; iter++)
    {
        lines.push_back(*iter);
    }

    sort(lines.begin(), lines.end(), compare);

    int biggest = INT_MAX;
    int n = lines.size();
    vector<int> dp(n+1, 0);
    for(int i = n-1 ; i>=0 ; i--)
    {
        pair<int, int> line = lines[i];
        if(visited.find(line.first) != visited.end())  { dp[i] = dp[i+1]+1; continue; }
        if( line.second >= biggest) {dp[i] = dp[i+1]; continue;}
        
        int selected = 0;
        for(int j = 0 ; j<i ; j++)
        {
            selected += (lines[j].second >= line.second && lines[j].second < biggest);
        }
        int discarded = i - (max_element(lines.begin(), lines.begin()+i, compare2) - lines.begin());

        if(selected>discarded && selected)
        {
            dp[i] = dp[i+1] + 1;
        }
        else
        {
            dp[i] = dp[i+1] + selected;
            visited.insert(line.first);
            biggest = line.second;
        }
    }

    cout<<dp[0] + m - n;
}