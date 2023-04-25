#include <iostream>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
       if(cin.eof())    break;
       else cout<<s<<endl;
    }
}