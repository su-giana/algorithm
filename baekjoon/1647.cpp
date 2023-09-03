#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

int n, m, target;
vector<vector<int> > dis;
vector<int> root(100000, 0);
vector<int> rank_(100000, 1);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int find(int cur)
{
    if(cur == root[cur])    return cur;
    return find(root[cur]);
}

void merge(int a, int b)
{
    int left = find(a);
    int right = find(b);

    if(rank_[left] > rank_[right])   swap(left, right);
    root[left] = right;
    if(rank_[left] == rank_[right]) rank_[right]++;
}

long long prim()
{
    sort(dis.begin(), dis.end());
    vector<int> last;
    long long ans = 0;

    for(int i = 0 ; i<m ; i++)
    {
        int a = find(dis[i][1]);
        int b = find(dis[i][2]);
        int cost = dis[i][0];

        if(find(a) == find(b))  continue;

        last = dis[i];
        ans += cost;
        merge(a, b);
    }

    return ans - last[0];
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<n ; i++)  root[i] = i;

    for(int i = 0 ; i<m ; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        dis.push_back({c, a-1, b-1});
    }

    cout<<prim();
}