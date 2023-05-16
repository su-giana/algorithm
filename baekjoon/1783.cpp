#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    long long n, m;
    cin>>n>>m;

    if(n==1)
    {
        cout<<1;
        return 0;
    }
    else if(n==2)
    {
        int ans = (m-1)/2 + 1>4 ? 4 : (m-1)/2 + 1;
        cout<<ans;
        return 0;
    }
    else
    {
        long long noWholeSteps = m>4 ? 4 : m;
        long long wholeSteps = m-2;
        cout<<max(noWholeSteps, wholeSteps);
        return 0;
    }
}