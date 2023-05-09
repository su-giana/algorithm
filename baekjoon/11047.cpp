#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> coins;
    for(int i = 0 ; i<n ; i++)
    {
        int coin;
        cin>>coin;
        coins.push_back(coin);
    }

    int ans = 0;
    for(int i = n-1 ; i>=0 ; i--)
    {
        int coin = coins[i];
        ans += (k / coin);
        k %= coin;
    }

    cout<<ans;
}