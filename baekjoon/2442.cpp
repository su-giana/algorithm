#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int star = 1;
    
    for(int i = n-1 ; i>=0 ; i--)
    {
        for(int j = 0 ; j<i ; j++)
            cout<<' ';
        for(int j = 0 ; j<star ; j++)
            cout<<'*';
        for(int j = 0 ; j<i ; j++)
            cout<<' ';
        star += 2;
        cout<<endl;
    }

    return 0;
}