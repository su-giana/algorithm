#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int five = 0;

    for(int i = 1 ; i<=n ; i++)
    {
        while(i%5 == 0)
        {
            i/=5;
            five++;
        }
    }

    cout<<five;
}