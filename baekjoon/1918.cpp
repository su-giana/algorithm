#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string cal;
int idx = 0;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string subst()
{
    stack<char> st;
    string ans = "";

    while(cal[idx] != ')')
    {
        if(cal[idx] == '*' || cal[idx] == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                ans += st.top();
                st.pop();
            }
            st.push(cal[idx]);
        }
        else if(cal[idx] == '+' || cal[idx] == '-')
        {
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            st.push(cal[idx]);
        }
        else if(cal[idx] == '(')
        {
            idx++;
            ans += subst();
        }
        else
        {
            ans += cal[idx];
        }
        idx++;
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    init();

    cin>>cal;

    stack<char> st;
    string ans = "";

    int c_size = cal.length();
    while(idx < c_size)
    {
        if(cal[idx] == '*' || cal[idx] == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                ans += st.top();
                st.pop();
            }
            st.push(cal[idx]);
        }
        else if(cal[idx] == '+' || cal[idx] == '-')
        {
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            st.push(cal[idx]);
        }
        else if(cal[idx] == '(')
        {
            idx++;
            ans += subst();
        }
        else
        {
            ans += cal[idx];
        }
        idx++;
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout<<ans;
}