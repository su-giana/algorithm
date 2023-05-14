#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;

    int n;
    cin>>n;

    int toDec = 0;
    int digit = n-1;

    for(int i = 0 ; i<n ; i++)
    {
        int s;
        cin>>s;
        toDec += s * pow(a, digit);
        digit--;
    }

    vector<int> st;
    while(toDec)
    {
        st.push_back(toDec % b);
        toDec /= b;
    }

    int m = st.size();
    for(int i = m-1 ; i>=0 ; i--)
    {
        cout<<st[i];
        if(i!=0)    cout<<" ";
    }
}