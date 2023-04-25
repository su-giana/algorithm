#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        
        int pos = s.find(',');
        int a = stoi(s.substr(0, pos));
        int b = stoi(s.substr(pos+1));
        
        cout<<a+b<<endl;
    }
}