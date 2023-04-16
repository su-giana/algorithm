#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>> piles, int k, int sum)
    {
        if(!k) return sum;

        vector<int> pile = piles.back();
        piles.pop_back();
        if(piles.empty())
        {
            for(int i = 0 ; i<k && !pile.empty() ; ++i)
            {
                    sum += pile.front();
                    pile.erase(pile.begin());
            }
            return sum;
        }

        int i = 0, ans = 0;
        for(int i = 0 ; i<=k && !pile.empty() ; i++)
        {
            if(i==0)    ans = maxValueOfCoins(piles, k, sum);
            else
            {
                sum += pile.front();
                ans = max(ans, maxValueOfCoins(piles, k-i, sum));
                pile.erase(pile.begin());
            }
        }
        return ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return maxValueOfCoins(piles, k, 0);
    }
};
*/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<int> dp(k+1, 0);

        for(int i = 0 ; i<n ; i++)
        {
            int m = piles[i].size();
            vector<int> newdp(k+1, 0);
            vector<int> sumarr(k+1, 0);

            for(int j = 1 ; j<=m && j<=k ; j++)
            {
                sumarr[j] = sumarr[j-1] + piles[i][j-1];
            }

            for(int j = 0 ; j<=k ; j++)
            {
                if(j>0 && !sumarr[j])   break;
                for(int l=0 ; l<=k-j ; l++)
                {
                    if(l>0 && !dp[l])    continue;
                    else newdp[l+j] = max({newdp[l+j], dp[l+j], sumarr[l+j], dp[l] + sumarr[j]});
                }
            }

            dp = newdp;
        }

        return dp[k];
    }
};