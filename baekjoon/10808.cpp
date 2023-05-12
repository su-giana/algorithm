#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();

    vector<int> chars(26, 0);
    for(int i = 0 ; i<n ; i++)
    {
        chars[s[i] - 'a']++;
    }

    for(int i = 0 ; i<26 ; i++)
    {
        cout<<chars[i]<<" ";
    }
}