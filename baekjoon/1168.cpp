#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void initTree(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = 1;
        return;
    }

    int mid = start + (end - start) / 2;
    initTree(2*node, start, mid);
    initTree(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void popJosepus(int cur, int start, int end, int target)
{
    tree[cur] -= 1;
    if(start == end)
    {
        cout<<start;
        return;
    }

    int mid = start + (end - start) / 2;
    if(tree[cur*2] >= target)
    {
        popJosepus(cur*2, start, mid, target);
    }
    else
    {
        popJosepus(cur*2 + 1, mid+1, end, target - tree[cur*2]);
    }
}

void solution(int n, int k)
{
    initTree(1, 1, n);
    int node = k;

    cout<<"<";
    for(int i = 1 ; i<n ; i++)
    {
        popJosepus(1, 1, n, node);
        cout<<", ";
        node += k-1;
        node = (node - 1) % tree[1] + 1;
    }
    popJosepus(1, 1, n, node);
    cout<<">";

}

int main()
{
    init();

    int n, k;
    cin>>n>>k;

    for(int i = 0 ; i<4*n ; i++)
        tree.push_back(0);

    solution(n, k);
}