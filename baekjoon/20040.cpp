#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int> > lines(500000);
vector<int> root(500000, 0);
vector<int> rank_(500000, 1);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int find(int cur)
{
    if(cur == root[cur])    return cur;
    return root[cur] = find(root[cur]);
}

void merge(int a, int b)
{
    int left = find(a);
    int right = find(b);

    if(rank_[left] > rank_[right])    root[right] = left;
    else if(rank_[left] < rank_[right])   root[left] = right;
    else
    {
        root[right] = left;
        rank_[left]++;
    }
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)  root[i] = i;

    for(int i = 0 ; i<m ; i++)
    {
        int start, end;
        cin>>start>>end;

        if(find(start) == find(end))
        {
            cout<<i+1;
            return 0;
        }

        merge(start, end);
    }

    cout<<0;
}