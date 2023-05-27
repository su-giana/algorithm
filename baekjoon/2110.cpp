#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long solution(vector<long long>& houses, int c)
{
    sort(houses.begin(), houses.end());
    int n = houses.size();

    long long maxGap = houses[n-1] - houses[0];
    long long minGap = maxGap;
    for(int i = 0 ; i<n-1 ; i++)
    {
        minGap = min(minGap, abs(houses[i+1] - houses[i]));
    }

    while(minGap <= maxGap)
    {
        long long cnt = 1;
        long long cur = houses[0];
        long long mid = minGap + (maxGap - minGap) / 2;
        for(int i = 1 ; i<n ; i++)
        {
            if(houses[i] - cur >= mid)
            {
                cur = houses[i];
                cnt++;
            }
        }

        if(cnt<c)
        {
            maxGap = mid-1;
        }
        else
        {
            minGap = mid+1;
        }
    }

    return maxGap;
}

int main()
{
    init();

    int n, c;
    cin>>n>>c;

    vector<long long> houses(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        long long house;
        cin>>house;
        houses[i] = house;
    }

    cout<<solution(houses, c);
}