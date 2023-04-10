#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<char> opened = {'(', '{', '['};
    vector<char> closed = {')', '}', ']'};

    bool isValid(string st) 
    {
        int n = st.length();
        if(n%2 == 1)     return false;

        vector<char> s(n);
        for(int i = 0 ; i<n ; i++)
        {
            s[i] = st[i];
        }

        int i = 1;
        while(s.size() != 0 && i<s.size())
        {
            if(s[i] == closed[0])
            { 
                if(s[i-1] != opened[0]) return false;
            }
            else if(s[i] == closed[1])
            {
                if(s[i-1] != opened[1]) return false;
            }
            else if(s[i] == closed[2])
            {
                if(s[i-1] != opened[2]) return false;
            }
            else
            {
                i++;
                continue;
            }
            s.erase(s.begin()+i);
            s.erase(s.begin() + i - 1);
            i=1;
        }

        if(s.size()==0) return true;
        else return false;
    }
};