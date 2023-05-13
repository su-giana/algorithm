#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long gcd(long long n, long long m)
{
    while(m)
    {
        long long temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}

long long toInt(long long n)
{
    long long dig = 0;
    long long num = 0;
    for(int i = 0 ; i<n ; i++)
    {
        num += pow(10, i);
    }
    return num;
}

int main()
{

    long long n, m;
    cin>>n>>m;

    long long g = gcd(n, m);
    for(int i = 0 ; i<g ; i++)
    {
        cout<<1;
    }
}