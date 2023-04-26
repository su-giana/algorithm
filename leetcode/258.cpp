#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;

        long long ans = 0;
        while(num)
        {
            cout<<ans<<endl;
            cout<<"num : "<<num<<endl;
            ans += num%10;
            num /= 10;
        }

        ans = addDigits(ans);

        return ans;
    }
};