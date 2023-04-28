#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution 
{
public:

    bool compStr(string &s1, string &s2)
    {
        int n = s1.length();
        vector<int> st;
        queue<int> que;
        for(int i = 0 ; i<n ; i++)
        {
            if(s1[i] != s2[i])
            {
                st.push_back(i);
                que.push(s1[i] - 'a');
            }
        }
        if(st.size() != 2)  return false;
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s1[i] != s2[i])
            {
                if(st.back() == i && que.front() == (s2[i] - 'a'))
                {
                    st.pop_back();   que.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs)
    {
        int n = strs.size();

        vector<int> ans(n, 0);

        for(int i = 0 ; i<n ; i++)
            ans[i] = i;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if(strs[i] == strs[j])
                {
                    int change = min(ans[i], ans[j]);
                    int changed = max(ans[i], ans[j]);
                    for(int i = 0 ; i<n ; i++)
                    {
                        if(ans[i] == changed)
                            ans[i] = change;
                    }
                }
                if(compStr(strs[i], strs[j]))
                {
                    cout<<i<<" "<<j<<endl;
                    int change = min(ans[i], ans[j]);
                    int changed = max(ans[i], ans[j]);
                    for(int i = 0 ; i<n ; i++)
                    {
                        if(ans[i] == changed)
                            ans[i] = change;
                    }
                    for(int i = 0 ; i<n ; i++)
                        cout<<ans[i]<<" ";
                    cout<<endl;
                }
            }
        }

        for(int i = 0 ; i<n ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;

        set<int> cnt;
        for(int i = 0 ; i<n ; i++)
        {
            cnt.insert(ans[i]);
        }

        return cnt.size();
    }
};