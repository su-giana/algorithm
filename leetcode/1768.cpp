#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n = word1.length(), m = word2.length();
        int longer = n>m ? n : m;
        int smaller = n>m ? m : n;
        string ans;

        for(int i = 0 ; i<smaller ; i++)
        {
            ans += word1[i];
            ans += word2[i];
        }

        if(longer==smaller)     return ans;
        else if(smaller == n)   return ans + word2.substr(smaller);
        else                    return ans + word1.substr(smaller);
    }
};