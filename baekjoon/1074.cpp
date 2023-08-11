#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, r, c;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

long long dc(long long cur, int n, int curX, int curY)
{
    if(n==0)    return cur;

    long long weight = pow(2, n-1) * pow(2, n-1);
    int stdX = curX + pow(2, n-1);
    int stdY = curY + pow(2, n-1);

    if(r < stdX && c < stdY)
    {
        return dc(cur, n-1, curX, curY);
    }
    else if(r < stdX && c >= stdY)
    {
        return dc(cur + weight, n-1, curX, stdY);
    }
    else if(r >= stdX && c < stdY)
    {
        return dc(cur + 2*weight, n-1, stdX, curY);
    }
    else
    {
        return dc(cur + 3*weight, n-1, stdX, stdY);
    }
}

int main()
{
    init();

    cin>>n>>r>>c;

    cout<<dc(0, n, 0, 0);
}