#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    // time limit exceeded
public:
    struct Scheme
    {
        int index;
        int remain;
        int person;
        
        Scheme(int _index, int _remain, int _person) : index(_index), remain(_remain), person(_person) {}
    };

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        int m = group.size();
        if(!minProfit)  return m;
        queue<Scheme> pos;
        int ans = 0;
        for(int i = m-1 ; i>=0 ; i--)
        {
            Scheme temp = Scheme(i, minProfit - profit[i], n - group[i]);
            pos.push(temp);
        }

        while(!pos.empty())
        {
            Scheme  sch = pos.front();
            pos.pop();

            if(sch.person < 0)  continue;
            if(sch.remain <= 0)
            {
                ans = (ans + 1) % (1000000007);
                sch.remain = 0;
            }
            for(int i = 0 ; i<sch.index ; i++)
            {
                if(group[i] <= sch.person)
                {
                    pos.push(Scheme(i, sch.remain - profit[i], sch.person - group[i]));
                }
                    
            }
        }
        return ans;
    }
};

class Solution2 {
public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
  {
    int m = group.size();
        
    vector<vector<int> > dp(n+1, vector<int>(minProfit+1, 0));
    dp[0][0] = 1;

    for(int k = 1 ; k<group.size()+1 ; k++)
    {
      int gr = group[k-1];
      int pr = profit[k-1];

      for(int i = n ; i>=gr ; i--)
      {
        for(int j = minProfit ; j>=0 ; j--)
        {
          dp[i][j] = (dp[i][j] + dp[i-gr][max(0, j-pr)]) % (1000000007);
        }
      }
    }

    int ans = 0;
    for(int i = 0 ; i<=n ; i++)
    {
      ans = ( ans + dp[i][minProfit] ) % 1000000007;
    }
    return ans;
  }
};