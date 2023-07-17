#include <iostream>
#include <vector>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    int n, m;
    cin>>n>>m;

    vector<bool> primes(m+1, true);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2 ; i*i<=m ; i++)
    {
        if(!primes[i]) continue;

        for(int j = 2*i ; j <= m ; j+=i)
        {
            primes[j] = false;
        }
    }

    for(int i =n ; i<=m ; i++)
    {
        if(primes[i])
            cout<<i<<'\n';
    }
}