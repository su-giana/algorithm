#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    int b;
    cin>>n>>b;
    vector<char> ans;

    while(n!=0)
    {
        int num;
        if(n>=b)
        {
            num = n % b;
            n /= b;
        }
        else
        {
            num = n;
            n=0;
        }
        
        if(num>9)
        {
            ans.push_back(num - 10 + 'A');
        }
        else
        {
            ans.push_back(num + '0');
        }
    }
    
    int m = ans.size();
    for(int i = m-1 ; i>=0 ; i--)
    {
        cout<<ans[i];
    }
}