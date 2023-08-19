#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
vector<long long> trees;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getTree(long long target)
{
    long long ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        ans += trees[i] > target ? trees[i] - target : 0;
        if(ans > 2000000000)    return 2000000001; 
    }
    return ans;
}

long long bs()
{
    long long left = 0;
    long long right = *max_element(trees.begin(), trees.end());

    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        if(getTree(mid) >= m)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return right;
}

int main()
{
    cin>>n>>m;

    for(long long i = 0 ; i<n ; i++)
    {
        long long tree;
        cin>>tree;
        trees.push_back(tree);
    }

    cout<<bs();
}