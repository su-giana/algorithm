#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> strings;

    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        strings.push_back(s);
    }

    for(int i = 0 ; i<n ; i++)
    {
        string s = strings[i];

        int max = 0;

        int len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, true));

        for(int j = 0 ; j<len-1 ; j++)
        {
            for(int k = 0 ; k<len-1-j ; k++)
            {
                dp[k][k+1+j] = dp[k+1][k+j] && (s[k] == s[k+1+j]);

                if(dp[k][k+1+j])
                {
                    max = j+1;
                }
            }
        }

        cout<<"Case #"<<i+1<<":"<<endl;
        if(!max) continue;
        for(int j = len - max -1 ; j>=0 ; j--)
        {
            if(dp[j][j+max]) cout<<s.substr(j, max+1)<<endl;
        }
    }
}