#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b)
{
    int temp, n;

    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    while(b != 0)
    {
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

pair<int, int> compute(pair<int, int> frac1, pair<int, int> frac2)
{
    int numer = frac1.first * frac2.second - frac2.first * frac1.second;
    int deno = frac1.second * frac2.second;
    int gcd = getGcd(numer, deno);
    return make_pair(numer/gcd, deno/gcd);
}

pair<int, int> getHenry(pair<int, int> fraction)
{
    if(fraction.first == 1)     return fraction;

    int demo = ((fraction.second / fraction.first)+1);
    pair<int, int> remain = compute(fraction, make_pair(1, demo));

    return getHenry(remain);
}

int main()
{   
    int t;
    cin>>t;
    for(int i = 0 ; i<t ; i++)
    {
        int a, b;
        cin>>a>>b;
        cout<<getHenry(make_pair(a, b)).second<<endl;
    }

    return 0;
}