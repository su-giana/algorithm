#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<long long> dp(n+1, 1);
    vector<vector<long long> > accumulated(n+1, vector<long long>(3, 1));
	accumulated[0][0] = 4;
	accumulated[0][1] = 2;
	accumulated[0][2] = 2;
    accumulated[1][0] = accumulated[0][0] + 2;
	accumulated[1][1] = accumulated[0][1] + 4;
	accumulated[1][2] = accumulated[0][2] + 2;
    
    for(int i = 2 ; i<=n ; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 1000000007;
        
        if(i>2)
        {
            dp[i] = (dp[i] + dp[i-3]) % 1000000007;
	        dp[i] = (dp[i] + accumulated[i-3][i%3]) % 1000000007;
        }
        
        if(i%3 == 0)
        {
            accumulated[i][0] = (accumulated[i-1][0] + dp[i]*4) % 1000000007;
	        accumulated[i][1] = (accumulated[i-1][1] + dp[i]*2) % 1000000007;
            accumulated[i][2] = (accumulated[i-1][2] + dp[i]*2) % 1000000007;
        }
        else if(i%3==1)
        {
            accumulated[i][0] = (accumulated[i-1][0] + dp[i]*2) % 1000000007;
	        accumulated[i][1] = (accumulated[i-1][1] + dp[i]*4) % 1000000007;
            accumulated[i][2] = (accumulated[i-1][2] + dp[i]*2) % 1000000007;
        }
        else
        {
            accumulated[i][0] = (accumulated[i-1][0] + dp[i]*2) % 1000000007;
	        accumulated[i][1] = (accumulated[i-1][1] + dp[i]*2) % 1000000007;
            accumulated[i][2] = (accumulated[i-1][2] + dp[i]*4) % 1000000007;
        }
    }
    
    return dp[n];
}