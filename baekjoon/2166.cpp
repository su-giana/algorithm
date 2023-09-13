#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

struct Spot
{
    long double x;
    long double y;

    Spot(long double x_, long double y_)
    {
        x = x_;
        y = y_;
    }
};

vector<Spot> spots(10000, Spot(0, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long double calSpace(Spot& a, Spot& b, Spot& c)
{
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) / 2.0;
}

int main()
{
    init();

    cin>>n;

    spots.resize(n, Spot(0, 0));

    for(int i = 0 ; i<n ; i++)
    {
        cin>>spots[i].x;
        cin>>spots[i].y;
    }

    long double ans = 0;

    for(int i = 1 ; i+1 < n ; i++)
    {
        ans += calSpace(spots[0], spots[i], spots[i+1]);
    }

    ans = ans < 0 ? ans*-1 : ans;
    cout<<fixed;
    cout.precision(1);
    cout<<ans;
}