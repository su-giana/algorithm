#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();

    vector<int> chars(26, -1);
    for(int i = 0 ; i<n ; i++)
    {
        if(chars[s[i] - 'a'] == -1) chars[s[i] - 'a'] = i;
    }

    for(int i = 0 ; i<26 ; i++)
    {
        cout<<chars[i]<<" ";
    }

    return 0;
}