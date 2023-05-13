#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int n, int m)
{
    while(m)
    {
        long long temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums;

        for(int i = 0 ; i<n ; i++)
        {
            int num;
            cin>>num;
            nums.push_back(num);
        }

        long long sum = 0;

        for(int i = 0 ; i<n-1 ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                sum += gcd(nums[i], nums[j]);
            }
        }

        cout<<sum<<endl;
    }
}