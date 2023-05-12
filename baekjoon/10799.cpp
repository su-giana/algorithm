#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();

    long long ans = 0;
    vector<long long> cnt;
    for(int i = 0 ; i<n ; i++)
    {
        if(s[i] == '(')
        {
            cnt.push_back(0);
        }
        else if(s[i] == ')' && s[i-1] == '(')
        {
            cnt.pop_back();
            int m = cnt.size();
            for(int j = 0 ; j<m ; j++)
                cnt[j]++;
        }
        else
        {
            ans += (cnt.back()+1);
            cnt.pop_back();
        }
    }

    cout<<ans;
}