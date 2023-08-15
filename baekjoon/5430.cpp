#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<int> split(string s)
{
    string temp;
    stringstream ss(s);
    vector<int> ans;

    while(getline(ss, temp, ','))
    {
        ans.push_back(stoi(temp));
    }
    return ans;
}

string solve(deque<int>& q, string cmd)
{
    int c_size = cmd.size();
    bool reversed = false;
    for(int i = 0 ; i<c_size ; i++)
    {
        if(cmd[i] == 'R')
        {
            reversed = !reversed;
        }
        else
        {
            if(!q.empty())
            {
                if(reversed)
                {
                    q.pop_back();
                }
                else
                {
                    q.pop_front();
                }
            }
            else
            {
                return "error";
            }
        }
    }

    string ans = "[";
    while(!q.empty())
    {
        if(reversed)
        {
            ans += to_string(q.back());
            q.pop_back();
        }
        else
        {
            ans += to_string(q.front());
            q.pop_front();
        }
        if(!q.empty())
            ans += ",";
    }
    ans += "]";
    return ans;
}

int main()
{
    init();
    int t;
    cin>>t;

    while(t--)
    {
        string cmd;
        cin>>cmd;

        int n;
        cin>>n;

        string s;
        cin>>s;

        if(n!=0)
        {
            vector<int> num = split(s.substr(1, s.length() - 1));
            deque<int> q(num.begin(), num.end());
            cout<<solve(q, cmd)<<'\n';
        }
        else
        {
            deque<int> q;
            cout<<solve(q, cmd)<<'\n';
        }
    }
}