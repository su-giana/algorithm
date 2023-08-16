#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(51, 0);
vector<long long> root(51, 0);
int n, m;

int find(int cur)
{
    while(cur!=root[cur])
    {
        cur = root[cur];
    }
    
    return cur;
}

void merge(int i, int j)
{
    int left = find(i);
    int right = find(j);

    if(left == right)   return;

    root[left] = right;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();
    
    cin>>n>>m;
    long long truth = 0;

    int t;
    cin>>t;
    while(t--)
    {
        int val;
        cin>>val;
        truth |= (1ll<<(val));
    }

    for(int i = 0 ; i<m ; i++)
    {
        int p;
        cin>>p;
        long long now = 0;
        for(int j = 0 ; j<p ; j++)
        {
            int person;
            cin>>person;
            now |= (1ll<<(person));
        }

        arr[i] = now;
    }

    for(int i = 0 ; i<m ; i++)
    {
        root[i] = i;
    }

    for(int i = 0 ; i<m ; i++)
    {
        for(int j = i+1 ; j<m ; j++)
        {
            if(arr[i] & arr[j])
            {
                merge(i, j);
            }
        }
    }

    for(int i = 0 ; i<m ; i++)
    {
        int rootNode = find(i);
        root[i] = rootNode;
        arr[rootNode] |= arr[i];
    }

    int ans = 0;

    for(int i = 0 ; i<m ; i++)
    {
        int rootNode = root[i];
        if(!(arr[rootNode] & truth))
        {
            ans++;
        }
    }

    cout<<ans;
}