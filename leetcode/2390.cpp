#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeStars(string s) 
    {
        int n = s.length();
        vector<char> answer;

        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]!= '*')
                answer.push_back(s[i]);
            else
                answer.pop_back();
        }

        string str(answer.begin(), answer.end());
        return str;
    }
};
