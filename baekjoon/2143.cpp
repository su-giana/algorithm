#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> segTreeA(4000, 0);
vector<int> arrA(1000, 0);
vector<long long> segTreeB(4000, 0);
vector<int> arrB(1000, 0);
long long t;
int n;
int m;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void initSeg(vector<long long>& tree, vector<int>& arr, int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = start + (end - start) / 2;
    initSeg(tree, arr, node*2, start, mid);
    initSeg(tree, arr, node*2 + 1, mid+1, end);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

long long query(vector<long long>& tree, int node, int start, int end, int left, int right)
{
    if(right < start || left > end) return 0;
    if(right>=end && left<=start)   return tree[node];

    int mid = start + (end - start) / 2;
    return query(tree, 2*node, start, mid, left, right) + query(tree, 2*node+1, mid+1, end, left, right);
}

int main()
{
    init();

    cin>>t>>n;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>arrA[i];
    }

    cin>>m;

    for(int i = 0 ; i<m ; i++)
    {
        cin>>arrB[i];
    }

    initSeg(segTreeA, arrA, 1, 0, n-1);
    initSeg(segTreeB, arrB, 1, 0, m-1);

    unordered_map<long long, long long> um;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i ; j<n ; j++)
        {
            um[query(segTreeA, 1, 0, n-1, i, j)]++;
        }
    }

    long long ans = 0;

    for(int i = 0 ; i<m ; i++)
    {
        for(int j = i ; j<m ; j++)
        {
            long long tmp = query(segTreeB, 1, 0, m-1, i, j);
            if(um[t - tmp])
            {
                ans += um[t - tmp];
            }

        }
    }

    cout<<ans;
}