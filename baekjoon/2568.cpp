#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > lines;
vector<pair<int, pair<int, int> > > ans;
vector<int> root(100000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int binSearch(int target)
{
    int left = 0;
    int right = ans.size() - 1;
    int closestGreaterIndex = -1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(ans[mid].second.second > target)
        {
            right = mid-1;
            closestGreaterIndex = mid;
        }
        else
        {
            left = mid+1;
        }
    }

    return closestGreaterIndex;
}

void solve()
{
    sort(lines.begin(), lines.end(), compare);

    ans.push_back(make_pair(0, lines[0]));

    for(int i = 1 ; i<n ; i++)
    {
        pair<int, int> now = lines[i];

        if(ans.back().second.second > now.second)
        {
            int idx = binSearch(now.second);
            ans[idx] = make_pair(i, lines[i]);
            if(idx>0)
            {
                root[i] = ans[idx-1].first;
            }
        }
        else if(ans.back().second.second < now.second)
        {
            root[i] = ans.back().first;
            ans.push_back(make_pair(i, now));
        }
    }

    vector<bool> isRequiredToErase(n, true);
    cout<<n - ans.size()<<'\n';
    int cur = ans.back().first;
    isRequiredToErase[cur] = false;
    while(cur != root[cur])
    {
        cur = root[cur];
        isRequiredToErase[cur] = false;
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(isRequiredToErase[i])
        {
            cout<<lines[i].first<<'\n';
        }
    }
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)  root[i] = i;

    for(int i = 0 ; i<n ; i++)
    {
        int left, right;
        cin>>left>>right;

        lines.push_back(make_pair(left, right));
    }

    solve();
}