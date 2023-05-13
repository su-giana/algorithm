#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void noZeroToBin(char c)
{
    switch(c - '0')
    {
        case 0:
        {
            cout<<"0";
            return;
        }
        case 1:
        {
            cout<<"1";
            return;
        }
        case 2:
        {
            cout<<"10";
            return;
        }
        case 3:
        {
            cout<<"11";
            return;
        }
        case 4:
        {
            cout<<"100";
            return;
        }
        case 5:
        {
            cout<<"101";
            return;
        }
        case 6:
        {
            cout<<"110";
            return;
        }
        case 7:
        {
            cout<<"111";
            return;
        }
    }
}

void toBin(char c)
{
    switch(c - '0')   
    {
        case 0:
        {
            cout<<"000";
            return;
        }
        case 1:
        {
            cout<<"001";
            return;
        }
        case 2:
        {
            cout<<"010";
            return;
        }
        case 3:
        {
            cout<<"011";
            return;
        }
        case 4:
        {
            cout<<"100";
            return;
        }
        case 5:
        {
            cout<<"101";
            return;
        }
        case 6:
        {
            cout<<"110";
            return;
        }
        case 7:
        {
            cout<<"111";
            return;
        }
    }
}

int main()
{
    string s;
    cin>>s;

    int n = s.length();

    noZeroToBin(s[0]);

    for(int i =1 ; i<n ; i++)
    {
        toBin(s[i]);
    }

}