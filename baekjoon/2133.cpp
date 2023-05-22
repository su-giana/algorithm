#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    int n;
    cin>>n;

    vector<long long> tiling(n+1, 0);
    tiling[0] = 1;

    for(int i = 1 ; i<=n ; i++)
    {
        if(i%2 == 1)    continue;

        long long sum = 0;
        for(int j = i-4 ; j>=0 ; j-=2)
        {
            sum += tiling[j]*2;
        }
        tiling[i] = tiling[i-2]*3 + sum;
    }

    cout<<tiling[n];
}