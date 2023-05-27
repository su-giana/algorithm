#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

double getDistance(double x1, double y1, double x2, double y2)
{
    return  sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double changeToMid1(double x1, double x2)
{
    return x1 + (x2 - x1) / 3;
}

double changeToMid2(double x1, double x2)
{
    return x2 - (x2 - x1) / 3;
}

int main()
{
    init();

    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy>>Dx>>Dy;

    int t = 100;
    while(t--)
    {
        double mid1 = getDistance(Ax, Ay, Cx, Cy);
        double mid2 = getDistance(Bx, By, Dx, Dy);

        if(mid1>=mid2)
        {
            Ax = changeToMid1(Ax, Bx);
            Ay = changeToMid1(Ay, By);
            Cx = changeToMid1(Cx, Dx);
            Cy = changeToMid1(Cy, Dy);
        }
        else if(mid1<mid2)
        {
            Bx = changeToMid2(Ax, Bx);
            By = changeToMid2(Ay, By);
            Dx = changeToMid2(Cx, Dx);
            Dy = changeToMid2(Cy, Dy);
        }
    }

    cout<<fixed;
    cout.precision(11);
    cout<<getDistance(Ax, Ay, Cx, Cy);
}