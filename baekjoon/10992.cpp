#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i = 1 ; i<=n ; i++)
    {
        if(i!=n)
        {
            for(int j = 0 ; j<n-i ; j++)
                cout<<' ';
            cout<<'*';
        
            if(i==1)    { cout<<endl; continue; }
        
            for(int j = 0 ; j<(i-1)*2 - 1 ; j++)
                cout<<' ';
            cout<<'*';
        }
        else
        {
            for(int i = 0 ; i<(2*n)-1 ; i++)
                cout<<'*';
        }
        
        cout<<endl;
        
    }
}