#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int ans = 0;
    while(n--)
    {
        int num;
        cin>>num;
        bool isDecimal = true;

        if(num == 1)    continue;

        for(int i = 2 ; i*i <= num ; i++)
        {
            if(num % i == 0)    { isDecimal = false; break; }
        }
        if(isDecimal)   ans++;
    }

    cout<<ans;
}