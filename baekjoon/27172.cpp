#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums(100000, 0);
vector<vector<int> > primes(100000, vector<int>());
vector<bool> exist(1000001, false);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
        exist[nums[i]] = true;
    }

    vector<int> isPrime(1000000, 0);

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 1 ; j*j<=nums[i] ; j++)
        {
            if(nums[i]%j == 0)   primes[i].push_back(j);
            if(nums[i]!=j * j && nums[i] %j == 0) primes[i].push_back(nums[i] / j);
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int cur : primes[i])
        {
            if(exist[cur])
            {
                isPrime[cur]++;
                isPrime[nums[i]]--;
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        cout<<isPrime[nums[i]]<<" ";
    }
}