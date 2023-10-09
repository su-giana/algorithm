#include <iostream>
#include <vector>

using namespace std;

int g, p;
int ans = 0;
vector<int> flights(100001, 0);
vector<int> root(100001, 0);

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
    int rootA = find(a);
    int rootB = find(b);

    rootA > rootB ? root[rootA] = rootB : root[rootB] = rootA;
}

int main()
{
    init();

    cin>>g>>p;

    for(int i = 0 ; i<p ; i++)
    {
        cin>>flights[i];
    }

    for(int i = 1 ; i<=g ; i++) root[i] = i;

    for(int i = 0 ; i<p ; i++)
    {
        int flight = flights[i];

        int space = find(flight);

        if(space == 0)  break;

        root[space] = space-1;

        ans++;
    }

    cout<<ans;
}