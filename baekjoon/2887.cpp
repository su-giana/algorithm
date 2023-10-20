#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<pair<int, int>, long long>

using namespace std;

int n;
vector<pair<int, long long> > planetsX;
vector<pair<int, long long> > planetsY;
vector<pair<int, long long> > planetsZ;
vector<int> root(100000, 0);

struct cmp
{
    bool operator()(pii& pa, pii& pb)
    {
        return pa.second > pb.second;
    }
};

priority_queue<pii, vector<pii>, cmp> vertices;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool compare(pair<int, long long>& a, pair<int, long long>& b)
{
    return a.second < b.second;
}

int find(int cur)
{
    if(cur == root[cur])    return cur;
    return root[cur] = find(root[cur]);
}

void merge(int p1, int p2)
{
    int rp1 = find(p1);
    int rp2 = find(p2);

    root[rp1] = rp2;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        long long x, y, z;
        cin>>x>>y>>z;

        planetsX.push_back(make_pair(i, x));
        planetsY.push_back(make_pair(i, y));
        planetsZ.push_back(make_pair(i, z));
    }

    sort(planetsX.begin(), planetsX.end(), compare);
    sort(planetsY.begin(), planetsY.end(), compare);
    sort(planetsZ.begin(), planetsZ.end(), compare);

    for(int i = 0 ; i<n ; i++)  root[i] = i;

    for(int i = 0 ; i<n-1 ; i++)
    {
        vertices.push(make_pair(make_pair(planetsX[i].first, planetsX[i+1].first), abs(planetsX[i].second - planetsX[i+1].second)));
        vertices.push(make_pair(make_pair(planetsY[i].first, planetsY[i+1].first), abs(planetsY[i].second - planetsY[i+1].second)));
        vertices.push(make_pair(make_pair(planetsZ[i].first, planetsZ[i+1].first), abs(planetsZ[i].second - planetsZ[i+1].second)));
    }

    long long ans = 0;
    while(!vertices.empty())
    {
        pii vertice = vertices.top();
        vertices.pop();

        int x = vertice.first.first;
        int y = vertice.first.second;
        if(find(x) == find(y))  continue;
        
        merge(x, y);
        ans += vertice.second;
    }

    cout<<ans;
}