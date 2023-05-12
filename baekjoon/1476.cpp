#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int e, s, m;
    cin>>e>>s>>m;

    int days = 1;

    while(true)
    {
        int _e = days%15 == 0 ? 15 : days%15;
        int _s = days%28 == 0 ? 28 : days%28;
        int _m = days%19 == 0 ? 19 : days%19;

        if(e==_e && _s==s && _m==m)
        {
            cout<<days;
            return 0;
        }
        days++;
    }
}