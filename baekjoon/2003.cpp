#include <iostream>
#include <vector>

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
    
    int n;
    long long m;
    cin>>n>>m;
    int cnt = 0;

    vector<int> nums(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    vector<long long> sums(n+1, 0);
    for(int i = 0 ; i<n ; i++)
    {
        sums[i+1] = sums[i] + nums[i];
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<=n ; j++)
        {
            if(sums[j] - sums[i] == m)
                cnt++;
        }
    }

    cout<<cnt;
}