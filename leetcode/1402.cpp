#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int cal_like(vector<int>& satisfaction)
    {
        int sum = 0;
        for(int i=0 ; i<satisfaction.size() ; i++)
        {
            sum += satisfaction[i] * (i + 1);
        }
        return sum;
    }

    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(), satisfaction.end());

        int max_sa = 0;
        for(int i = 0 ; i < satisfaction.size() ; i++)
        {
            vector<int> temp;
            temp.assign(satisfaction.begin() + i, satisfaction.end());
            max_sa = max(max_sa, cal_like(temp));
        }

        return max_sa;
    }
};