#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int n = s.length();
    for(int i = 0 ; i<n ; i++)
    {
        if(i && i%10==0)    cout<<endl;
        cout<<s[i];
    }
    
    return 0;
}