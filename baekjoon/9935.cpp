#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> map;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    string total, exp;
    cin>>total>>exp;

    char start = exp[0];

    stack<string> st;

    int t_size = total.length();
    for(int i = 0 ; i<t_size ; i++)
    {
        if(st.empty())
        {
            string next(1, total[i]);
            st.push(next);
        }
        else
        {
            if(total[i] == start)
            {
                string next(1, total[i]);
                st.push(next);
            }
            else
            {
                string cur = st.top();
                st.pop();
                st.push(cur + total[i]);
            }
        }
        if(st.top() == exp)
        {
            st.pop();
        }
    }

    if(st.empty())
    {
        cout<<"FRULA";
    }
    else
    {
        vector<string> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        int a_size = ans.size();
        for(int i = a_size-1 ; i>=0 ; i--)
        {
            cout<<ans[i];
        }
    }
}