#include <iostream>
#include <vector>

using namespace std;

int gcd(int n, int m)
{
    while(m)
    {
        int temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}

int main()
{
    int n, m;
    cin>>n>>m;

    int g = gcd(n, m);
    long long s = n * m / g;
    cout<<g<<endl;
    cout<<s;
}