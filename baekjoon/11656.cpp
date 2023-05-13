#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<string> strs;

    int n = s.length();
    for(int i = 0 ; i<n ; i++)
    {
        strs.push_back(s.substr(i));
    }
    sort(strs.begin(), strs.end());

    int m = strs.size();
    for(int i = 0 ; i<m ; i++)
    {
        cout<<strs[i]<<endl;
    }
}