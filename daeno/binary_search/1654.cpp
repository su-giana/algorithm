#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long n, k;
vector<long long> lines;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getRes(long long target)
{
    long long res = 0;
    for(long long i = 0 ; i<n ; i++)
    {
        res += lines[i] / target;
        if(res > 1000000) return 1000001;
    }
    return res;
}

long long bs()
{
    long long left = 1;
    long long right = *max_element(lines.begin(), lines.end());

    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        if(getRes(mid) >= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right;
}

int main()
{
    init();

    cin>>n>>k;

    for(long long i = 0 ; i<n ; i++)
    {
        long long line;
        cin>>line;
        lines.push_back(line);
    }

    cout<<bs();
}