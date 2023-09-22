#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    long long n;
    long long s;
    cin>>n>>s;

    vector<long long> nums(n, 0);
    for(long long i = 0 ; i<n ; i++)
    {
        long long num;
        cin>>num;
        nums[i] = num;
    }

    vector<long long> sums(n+1, 0);
    for(long long i = 0 ; i<n ; i++)
    {
        sums[i+1] = sums[i] + nums[i];
    }

    long long minTemp = n+1;
    long long left = 0;
    long long right = 0;

    while(left <= right && right <= n)
    {
        long long cur = sums[right] - sums[left];
        while(right <= n && cur < s)
        {
            right++;
            cur = sums[right] - sums[left];
        }

        if(right > n)   break;

        while(left<=right && cur >= s)
        {
            left++;
            cur = sums[right] - sums[left];
        }

        if(left > n)    break;

        minTemp = min(minTemp, right - left + 1);
        right++;
    }

    minTemp = minTemp > n ? 0 : minTemp;
    cout<<minTemp;
}