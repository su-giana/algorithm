#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int, int> > blocks(n, make_pair(0, 0));
    vector<long long> horizon(n, 0);
    vector<long long> vertical(n, 0);

    for(int i = 0 ; i<n ; i++)
    {
        int a, b;
        cin>>a>>b;
        blocks[i].first = max(a, b);
        blocks[i].second = min(a, b);
    }

    horizon[0] = blocks[0].first;
    vertical[0] = blocks[0].second;
    for(int i = 1 ; i<n ; i++)
    {
        horizon[i] = max(horizon[i-1] + abs(blocks[i].second - blocks[i-1].second) + blocks[i].first,
                    vertical[i-1] + abs(blocks[i].second - blocks[i-1].first) + blocks[i].first);
        vertical[i] = max(horizon[i-1] + abs(blocks[i].first - blocks[i-1].second) + blocks[i].second,
            vertical[i-1] + abs(blocks[i].first - blocks[i-1].second) + blocks[i].second);
    }
    
    cout<<max(horizon[n-1], vertical[n-1]);
}