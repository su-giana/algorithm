#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<long long> tree(400000, 0);
vector<long long> lazy(400000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void printTree(int node, int begin, int end)
{
    if(begin != end)
    {
        int mid = begin + (end - begin) / 2;
        printTree(node*2, begin, mid);
        printTree(node*2 + 1, mid+1, end);
    }
    else
    {
        cout<<tree[node]<<' ';
    }
}

void paint(int node, int left, int right, int begin, int end, long long color)
{
    if(left >= begin && right <= end)
    {
        if(tree[node] == 0)
            tree[node] = color;
        else
        {
            return;
        }
    }
    else if(left > end || right < begin)    return;

    if(right <= left)   return;

    int mid = left + (right - left) / 2;

    paint(node*2, left, mid, begin, end, color);
    paint(node*2 + 1, mid+1, right, begin, end, color);
}

int main()
{
    init();

    cin>>n>>q;

    for(int i = 0 ; i<q ; i++)
    {
        int a, b, x;
        cin>>a>>b>>x;
        paint(1, 0, n-1, a-1, b-1, x);
    }

    printTree(1, 0, n-1);
}
