#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char toOctal(string s)
{
    int n = s.length();
    int sum = 0;

    for(int i = 0 ; i<n ; i++)
    {
        sum += (s[i] - '0') * pow(2, n-1-i);
    }

    return sum + '0';
}

int main()
{
    string s;
    cin>>s;

    int n = s.length();
    int fr = n%3;
    vector<char> st;

    if(fr!=0)   st.push_back(toOctal(s.substr(0, fr)));

    for(int i =fr ; i<n ; i+=3)
    {
        st.push_back(toOctal(s.substr(i, 3)));
    }

    int m = st.size();
    for(int i = 0 ; i<m ; i++)
    {
        cout<<st[i];
    }
}