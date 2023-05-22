#include <iostream>
#include <vector>

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

    string cypher;
    cin>>cypher;

    int n = cypher.length();
    vector<long long>       dp(n, 0); 
    if(cypher[0] == '0')    { cout<<0; return 0; }
    else                    dp[0] = 1;

    if(n>=2)
    {
        int temp = stoi(cypher.substr(0, 2));
        if(temp<10)             dp[1] = 0;
        else if(temp<27 && temp%10 != 0)        dp[1] = 2;
        else if(temp%10 == 0 && temp>=30)       { cout<<0; return 0; }
        else if(temp%10==0)                     { dp[1] = 1; }
        else                    dp[1] = 1;
    }

    for(int i = 2 ; i<n ; i++)
    {
        char c = cypher[i];

        if(c=='0')
        {
            if(cypher[i-1] != '2' && cypher[i-1] != '1')    break;
            dp[i] = dp[i-2];
            continue;
        }

        
        int cur = stoi(cypher.substr(i-1, 2));
        if(cur>10 && cur<=26)    dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
        else                    dp[i] = dp[i-1];
    }

    cout<<dp[n-1];
}