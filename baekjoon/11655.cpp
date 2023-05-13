#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int n = s.length();
        for(int i = 0 ; i<n ; i++)
        {
            char c = s[i];
            if(c>='A' && c<='Z')
            {
                if(c > 'Z' - 13)
                {
                    c = c - 'Z' + 12 + 'A';
                }
                else
                {
                    c = c + 13;
                }
                cout<<c;
            }
            else if(c>='a' && c<='z')
            {
                if(c > 'z' - 13)
                {
                    c = c - 'z' + 12 + 'a';
                }
                else
                {
                    c = c + 13;
                }
                cout<<c;
            }
            else
            {
                cout<<c;
            }
        }
    }
}