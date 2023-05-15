#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getWood(long long saw, vector<long long>& trees)
{
    long long n = trees.size();
    long long res = 0;

    for(long long i = 0 ; i<n ; i++)
    {
        if(trees[i] - saw > 0)
        {
            if(res + trees[i] - saw > 2000000000)
            {
                return 2000000000;
            }
            res += (trees[i] - saw);
        }
    }

    return res;
}

long long binSearch(vector<long long>& trees, long long left, long long right, long long m)
{
    long long leftWood = getWood(left, trees);
    long long rightWood = getWood(right, trees);

    while(left<=right)
    {
        long long mid = left + (right - left) / 2;
        long long res = getWood(mid, trees);

        if(res>=m)
        {
            left = mid+1;
            leftWood = getWood(mid+1, trees);
        }
        else
        {
            right = mid-1;
            rightWood = getWood(mid-1, trees);
        }
    }

    return left-1;
}

int main()
{
    init();
    long long n, m;
    cin>>n>>m;

    vector<long long> trees(n, 0);
    long long biggest = 0;
    for(long long i = 0 ; i<n ; i++)
    {
        long long tree;
        cin>>tree;
        trees[i] = tree;
        if(tree>biggest)    biggest = tree;
    }
    
    cout<<binSearch(trees, 0, biggest, m);
}