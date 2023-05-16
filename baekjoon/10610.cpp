#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char c1, char c2)
{
    return c1>c2;
}

int main()
{
    string s;
    cin>>s;

    int n = s.length();
    
    sort(s.begin(), s.end(), compare);
    if(s[n-1] != '0')   {cout<<-1; return 0;}

    int sum = 0;
    for(int i = 0 ; i<n ; i++)
    {
        sum += s[i] - '0';
    }

    if(sum%3 == 0)  cout<<s;
    else            cout<<-1;
}