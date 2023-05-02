#include <iostream>
#include <vector>

using namespace std;

bool VPS(string s)
{
    int n = s.length();
    vector<char> pars;

    for(int i = 0 ; i<n ; i++)
    {
        char par = s[i];
        if(par == '(')  pars.push_back(par);
        else
        {
            if(pars.empty())    return false;
            pars.pop_back();
        }
    }
    if(pars.size() == 0)    return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        if(VPS(s))
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}