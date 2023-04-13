#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n = pushed.size();
        vector<int> simulator;
        vector<int> compare;

        int temp = 0;
        while(!pushed.empty())
        {
            if(!simulator.empty() && popped[temp] == simulator.back())
            {
                compare.push_back(simulator.back());
                simulator.pop_back(); 
                temp++;
            }
            else if(popped[temp] == pushed.front())
            {
                compare.push_back(popped[temp]);
                pushed.erase(pushed.begin());
                temp++;
            }
            else if(popped[temp] != pushed.front())
            {
                simulator.push_back(pushed.front());
                pushed.erase(pushed.begin());
            }
            else
                return false;
        }

        for(int i = 0 ; i<simulator.size() ; i++)
            cout<<simulator[i]<<" ";
        
        while(!simulator.empty())
        {
            compare.push_back(simulator.back());
            simulator.pop_back();
        }

        for(int i = 0 ; i<n ; i++)
        {
            if(compare[i] != popped[i])     return false;
        }
        return true;
    }

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int j = 0;

        for(auto val : pushed)
        {
            st.push(val);
            while(st.size()>0 && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        return st.size()==0;
    }
};

