#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
vector<long long> votes1(100, 0);
vector<long long> votes2(100, 0);
long long initial = 0;

int n, p;

long long gcd(long long a, long long b)
{
    while(b!=0)
    {
        long long temp = a;
        a = b;
        b = temp%b;
    }

    return a;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>p;

    if(n==1)
    {
        cin>>votes1[n]>>votes2[n];
        cout<<1<<" "<<1;
        return 0;
    }

    for(int i = 0; i <n ; i++)  cin>>votes1[i];

    for(int i = 0 ; i<n ; i++)  initial = gcd(initial, votes1[i]);

    for(int i = 0 ; i<n ; i++)
    {
        votes1[i] = (votes1[i] / initial);
    }

    cout<<accumulate(votes1.begin(), votes1.end(), 0)<<" ";

    // =================

    for(int i = 0; i<n ; i++)  cin>>votes2[i];

    initial = votes2[0];

    for(int i = 1 ; i<n ; i++)  initial = gcd(initial, votes2[i]);

    long long mul = 0;

    for(int i = 0 ; i<n ; i++)
    {
        votes2[i]= (votes2[i] / initial);
        if(votes2[i] == 0)  continue;
        mul = max(votes1[i] % votes2[i] == 0 ? votes1[i] / votes2[i] : votes1[i] / votes2[i] + 1, mul);
    }

    if(mul>1)
        cout<<accumulate(votes2.begin(), votes2.end(), 0) * mul;
    else
        cout<<accumulate(votes2.begin(), votes2.end(), 0);
}