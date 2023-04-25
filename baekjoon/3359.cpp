#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int, int> > dp(n, make_pair(0, 0));
    // first contains whole width
    // secibd contains height of the square

    for(int i = 0 ; i<n ; i++)
    {
        int a,b;
        cin>>a>>b;
        if(!i)
        {
            dp[i].first = max(a, b);
            dp[i].second = min(a, b);
            continue;
        }

        int minLine = min(a, b);
        int maxLine = max(a, b);
        int preHeight = dp[i-1].second;

        if(minLine > preHeight)
        {
            dp[i].first = minLine - preHeight + maxLine;
            dp[i].second = maxLine;
        }
        
    }

    for(int i = 0 ; i< n ; i++)
        cout<<dp[i].first<<" "<<dp[i].second<<endl;

    cout<<dp[n-1].first;
}