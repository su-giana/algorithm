#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;
vector<long long> liq;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bs()
{
    long long left = 0;
    long long right = n-1;

    long long leftSide = liq[left];
    long long rightSide = liq[right];
    long long minNow = abs(leftSide + rightSide);

    while(left < right)
    {
        long long cur = liq[left] + liq[right];
        if(minNow >= abs(cur))
        {
            minNow = abs(cur);
            leftSide = liq[left];
            rightSide = liq[right];
        }
        
        if(cur < 0)
        {
            left += 1;
        }
        else
        {
            right -= 1;
        }
    }

    cout<<leftSide<<" "<<rightSide;
}

int main()
{
    init();

    cin>>n;
    for(long long i = 0 ; i<n ; i++)
    {
        long long l;
        cin>>l;
        liq.push_back(l);
    }

    bs();
}