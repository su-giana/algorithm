#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());
        vector<int> sum;

        for(int i = 0 ; i<spells.size() ; i++)
        {
            int l = 0, r = potions.size() - 1;
            
            while(l<r)
            {
                int mid = l + (r - l)/2;

                if((long long)potions[mid]*spells[i] >= success)
                    r = mid;
                else
                    l = mid+1;
            }
            if((long long)potions[r]*spells[i] < success) sum.push_back(0);
            else    sum.push_back(potions.size() - r);
        }   

        return sum;
    }
};