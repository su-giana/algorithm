#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    string s;

    while(true)
    {
        if(n==0)    { cout<<"0"; return 0; }
        if(n==1)
        {
            s = '1' + s;
            break;
        }

        long long mod = n % -2;
        long long div = n / -2;

        if(mod == -1)
        {
            mod = 1;
            div += 1;
        }

        n = div;
        char c = mod + '0';
        s = c + s;
    }

    cout<<s;
}