#include <iostream>
#include <vector>

using namespace std;

int t;
int h, w, n;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    cin>>t;

    while(t--)
    {
        cin>>h>>w>>n;

        n-=1;

        int mod = n % h + 1;
        int div = n / h + 1;

        if(div < 10)
            cout<<to_string(mod) + "0" + to_string(div)<<endl;
        else
            cout<<to_string(mod) + to_string(div)<<endl;
    }
}