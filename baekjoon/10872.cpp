#include <iostream>
#include <vector>

using namespace std;

long long factorial(int k)
{
    if(k==0 || k==1)    return 1;
    return k * factorial(k-1);
}

int main()
{
    int n;
    cin>>n;

    cout<<factorial(n);
}