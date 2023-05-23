#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    string s;
    cin>>s;
    int n = s.length();
    
    deque<char> s1;
    deque<char> s2;

    for(int i = 0 ; i<n ; i++)
        s1.push_back(s[i]);

    int m;
    cin>>m;
    for(int i = 0 ; i<m ; i++)
    {
        char cmd;
        cin>>cmd;

        switch(cmd)
        {
            case 'L':
            {
                if(s1.empty())  continue;
                s2.push_back(s1.back());
                s1.pop_back();
                break;
            }
            case 'D':
            {
                if(s2.empty())  continue;
                s1.push_back(s2.back());
                s2.pop_back();
                break;
            }
            case 'B':
            {
                if(s1.empty())  continue;
                s1.pop_back();
                break;
            }
            case 'P':
            {
                char c;
                cin>>c;
                s1.push_back(c);
                break;
            }
        }
    }

    string ans = "";
    while(!s1.empty())
    {
        cout<<s1.front();
        s1.pop_front();
    }
    while(!s2.empty())
    {
        cout<<s2.back();
        s2.pop_back();
    }

    cout<<ans;
}