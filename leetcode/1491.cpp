#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(), salary.end());
        
        int ans = 0;
        int n = salary.size();
        for(int i = 1 ; i<n-1 ; i++)
        {
            ans += salary[i];
        }

        cout<<ans<<n-2<<endl;
        double avg = (double) ans / (n-2);
        return avg;
    }
};