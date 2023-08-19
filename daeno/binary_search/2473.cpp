#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<long long> liqs;
vector<long long> sample;
long long n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bs()
{
    long long minRes = LLONG_MAX;
    vector<long long> ans = {-1, -1, -1};

    for(int i = 0 ; i<n ; i++)
    {
        long long left = 0;
        long long right = n-1;
        while(left < right)
        {
            if(left == i)   left++;
            if(right == i)  right--;
            if(left >= right)   break;

            long long cur = liqs[left] + liqs[right] + liqs[i];

            if(minRes >= llabs(cur))
            {
                minRes = llabs(cur);
                ans = {liqs[left], liqs[right], liqs[i]};
            }

            if(cur < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(int i = 0 ; i<3 ; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    init();

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        int val;
        cin>>val;
        liqs.push_back(val);
    }

    sort(liqs.begin(), liqs.end());

    bs();
}