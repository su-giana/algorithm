#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string s, char delimeter)
{
    vector<string> ans;
    stringstream ss(s);
    string temp;

    while(getline(ss,temp,delimeter))
    {
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    vector<string> ans = split(s, ' ');

    if(ans[0] == "")   { cout<<ans.size()-1; return 0; }

    cout<<ans.size();
}