#include <iostream>
#include <vector>

using namespace std;

long long x1, x2, x3, x4;
long long y1_, y2, y3, y4;

struct p
{
    long long x, y;
    bool operator<=(p const& pi)
    {
        if(x == pi.x)
        {
            return y <= pi.y;
        }
        return x <= pi.x;
    }

    p(long long x_, long long y_)
    {
        x = x_;
        y = y_;
    }
};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long ccw(p &p1, p &p2, p &p3)
{
    long long s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);

    if(s>0) return 1;
    if(s==0)   return 0;
    return -1;
}

bool isintersect(pair<p, p>& l1, pair<p, p>& l2)
{
    p p1 = l1.first;
    p p2 = l1.second;
    p p3 = l2.first;
    p p4 = l2.second;

    long long p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    long long p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(p1p2 == 0 && p3p4 == 0)
    {
        if(p2<=p1)   swap(p1, p2);
        if(p4<=p3)   swap(p3, p4);

        return p3<=p2 && p1<=p4;
    }

    return p1p2<=0 && p3p4<=0;
}

int main()
{
    init();

    cin>>x1>>y1_>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    p p1 = p(x1, y1_);
    p p2 = p(x2, y2);
    p p3 = p(x3, y3);
    p p4 = p(x4, y4);

    pair<p, p> l1 = make_pair(p1, p2);
    pair<p, p> l2 = make_pair(p3, p4);

    if(isintersect(l1, l2))
        cout<<1;
    else
        cout<<0;
}