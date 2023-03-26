#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pibonacci(int n)
    {
        vector<int> pibo(1000);
        pibo[0] = 1;

        for(int i=1 ; i<=n ; i++)
        {
            pibo[i] = pibo[i-1] * i;
        }

        return pibo;
    }

    int uniquePaths(int m, int n) 
    {
        vector<int> pibo = pibonacci(m+n-2);

        return (pibo[m+n-2] / pibo[m-1]) / pibo[n-1];
    }
};