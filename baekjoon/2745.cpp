#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string s;
    int b;
    cin>>s>>b;
    
    int digit = 0;
    int n = s.length();

    long long ans = 0;
    for(int i = n-1 ; i>=0 ; i--)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            ans += (s[i] - 'A' + 10) * pow(b, digit);
        }
        else
        {
            ans += (s[i] - '0') * pow(b, digit);
        }
        digit++;
    }
    cout<<ans;
}