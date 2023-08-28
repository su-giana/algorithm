#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<bool> arr(4000000, true);
int n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int partialSum(int left, int right)
{
    long long ans = 0;
    for(int i = left ; i<=right ; i++)
    {
        if(arr[i])  ans+=i;
        if(ans > n) return n+1;
    }

    return ans;
}

int main()
{
    init();
    cin>>n;
    
    arr[0] = false;     arr[1] = false;
    for(int i = 2 ; i*i<=n ; i++)
    {
        if(!arr[i]) continue;

        for(int j = i*i ; j<=n ; j+=i)
        {
            arr[j] = false;
        }
    }

    if(n==1)    { cout<<0; return 0; }
    if(n==2)    { cout<<1; return 0; }

    int left = 0;
    int right = 2;
    int ans = 0;

    while(left <= right)
    {
        if(partialSum(left, right) == n)    ans++;

        while(right <= n && partialSum(left, right)<n)
        {
            right++;
            while(!arr[right] && right<=n)  right++;
        }

        if(right > n)   break;

        left++;
        while(!arr[left] && left <= right) left++;
    }

    cout<<ans;
}