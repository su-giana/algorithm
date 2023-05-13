#include <iostream>
#include <vector>

using namespace std;

int edit(vector<char>& str, char cmd, char c, int cursor)
{
    str.insert(str.begin() + cursor, c);
    return cursor + 1;
}

int edit(vector<char>& str, char cmd, int cursor)
{
    switch(cmd)
    {
        case 'L':
        {
            if(cursor>0)
            {
                cursor--;
            }
            return cursor;
        }
        case 'D':
        {
            if(cursor<str.size())
            {
                cursor++;
            }
            return cursor;
        }
        case 'B':
        {
            if(cursor>0)
            {
                cursor--;
                str.erase(str.begin() + cursor);
            }
            return cursor;
        }
    }
    return cursor;
}

int main()
{
    string s;
    cin>>s;
    vector<char> str;
    
    int n = s.length();
    int cursor = n;
    for(int i = 0 ; i<n ; i++)
    {
        str.push_back(s[i]);
    }

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        char cmd;
        cin>>cmd;

        if(cmd=='P')
        {
            char c;
            cin>>c;

            cursor = edit(str, cmd, c, cursor);
        }
        else
        {
            cursor = edit(str, cmd, cursor);
        }
    }
    
    int m = str.size();
    for(int i = 0 ; i<m ; i++)
    {
        cout<<str[i];
    }
}