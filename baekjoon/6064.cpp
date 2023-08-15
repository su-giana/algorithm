#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int t;

int m, n, x, y;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int gcd()
{
    int a = m, b = n;
    while(b)
    {
        int tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

long long getMaximum()
{
    return (m*n) / gcd();
}

long long solve()
{
    long long maximum = getMaximum();

    for(int i = x ; i<=maximum ; i+=m)
    {
        if((i-x)%m == 0 && (i-y) % n == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    init();

    cin>>t;
    while(t--)
    {
        cin>>m>>n>>x>>y;

        cout<<solve()<<'\n';
    }
}