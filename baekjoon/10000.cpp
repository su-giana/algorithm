#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<long long, long long> > circles;
long long answer = 0;

bool compare(pair<long long, long long>& a, pair<long long, long long>& b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int cntDiv(int cur)
{
    
    long long begin = circles[cur].first;
    long long end = circles[cur].second;
    bool canFill = true;

    int cnt = 0;
    long long prev = circles[cur].first;
    cur+=1;
    while(cur<circles.size() && circles[cur].second<=end)
    {
        cnt++;
        if(prev != circles[cur].first)  canFill = false;
        prev = circles[cur].second;
        cur = cntDiv(cur);
    }

    
    if(cnt && prev==end)    { answer += canFill; }
    
    return cur;
}


int main()
{
    init();

    int n;
    cin>>n;

    answer += n+1;

    for(int i = 0 ; i < n ; i++)
    {
        long long x, r;
        cin>>x>>r;
        circles.push_back(make_pair(x-r, x+r));
    }

    sort(circles.begin(), circles.end(), compare);

    int index = 0;

    while(index<n)
    {
        index = cntDiv(index);
    }

    cout<<answer;
}