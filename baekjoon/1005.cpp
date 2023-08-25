#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

int n, k, w;
vector<int> consumed;
vector<vector<int> > building;
vector<long long> stacked;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cur)
{
    long long tmp = 0;
    int n_size = building[cur].size();
    for(int i = 0 ; i<n_size ; i++)
    {
        int next = building[cur][i];
        
        if(stacked[next] == -1)
        {
            dfs(next);
            tmp = max(tmp, stacked[next]);
        }
        else
        {
            tmp = max(tmp, stacked[next]);
        }
    }

    stacked[cur] = tmp + consumed[cur];
}

int main()
{
    init();

    int t;
    cin>>t;

    for(int l= 0 ; l<t ; l++)
    {
        consumed.resize(1000, 0);
        building.resize(1000, vector<int>());
        stacked.resize(1000, -1);

        cin>>n>>k;

        for(int i = 0 ; i<n ; i++)
        {
            cin>>consumed[i];
        }

        for(int i = 0 ; i<k ; i++)
        {
            int a, b;
            cin>>a>>b;
            building[b-1].push_back(a-1);
        }

        cin>>w;

        dfs(w-1);
        cout<<stacked[w-1]<<'\n';

        consumed.clear();
        building.clear();
        stacked.clear();
    }
}