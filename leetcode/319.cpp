#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) 
    {
        if(!n)  return 0;

        vector<int> bulbs(n+1, 0);

        int ans = 1;
        for(int i = 2 ; i*i<=n ; i++)
        {
            ans+=1;
        }

        return ans;
    }
};