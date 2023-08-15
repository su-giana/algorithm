#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int t;

int m, n, x, y;

set<long long> s;

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

    for(long long i = 0 ; (m*i) + x <= maximum ; i++)
    {
        long long val = m*i + x;
        s.insert(val);
    }

    for(long long j = 0 ; (n*j) + y <= maximum ; j++)
    {
        long long val = n*j + y;
        if(s.find(val)!=s.end())
        {
            return val;
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
        s.clear();
    }
}