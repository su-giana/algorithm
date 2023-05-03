#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long getCase(vector<long long>& cables, long long k)
{
    long long ans = 0;
    int n = cables.size();
    for(int i = 0 ; i<n ; i++)
    {
        ans += cables[i] / k;
        if(ans > 1000000) return 1000001;
    }
    return ans;
}

long long binSearch(const pair<long long, long long>& a, const pair<long long, long long>& b, vector<long long>& cables, long long k)
{
    pair<long long, long long> left = a;
    pair<long long, long long> right = b;

    while(left.first <= right.first)
    {
        long long mid = (left.first + right.first)/2;
        long long midC = getCase(cables, mid);

        if(midC >= k)
        {
            left.first = mid+1;
            left.second = getCase(cables, left.first);
        }
        else if(midC < k)
        {
            right.first = mid-1;
            right.second = getCase(cables, right.first);
        }
    }
    return left.first-1;
}

int main()
{
    long long k, n;
    cin>>k>>n;

    vector<long long> cables;
    for(int i = 0 ; i<k ; i++)
    {
        int cable;
        cin>>cable;
        cables.push_back(cable);
    }

    long long right = *max_element(cables.begin(), cables.end());
    
    long long ans = binSearch(make_pair(1, getCase(cables, 1)), make_pair(right, getCase(cables, right)), cables, n);
    cout<<ans;
}