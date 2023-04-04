#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
/* class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n, vector<bool>(n, true));
        vector<int> maxlen(n, 1);

        for(int i = 1 ; i<n ; i++)
        {
            for(int j = 0 ; j<n-i ; j++)
            {
                if(dp[j][j+i-1] && dp[j+1][j+i] && dp[j+1][j+i-1])
                {
                    if(s[j] != s[j+i])  
                    {
                        dp[j][j+i] = true;
                        maxlen[j]++;
                    }
                    else    dp[j][j+i] = false;
                }
                else    dp[j][j+i] = false;
            }
        }

        int i = 0, answer = 0;
        while(i<n)
        {
            i += maxlen[i];
            answer++;
        }

        return answer;
    }
}; */

// O(n)
class Solution {
public:
    int partitionString(string s) {
      int alphabet = 0, ans = 1, i = 0;

      while(i<s.length())
      {
        int val = s[i] - 'a';

        if(alphabet & (1<<val))
        {
          ans++;
          alphabet = 0;
        }
        
        alphabet = alphabet | (1<<val);
        i++;
      }

      return ans;
    }
};