#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

vector<int> steps;
vector<vector<vector<int> > > dp(100001, vector<vector<int> > (5, vector<int>(5, INF)));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int move(int cur, int next)
{
    if(cur == next) return 1;
    if(cur == 0)    return 2;
    if(abs(cur - next) == 2)    return 4;
    return 3;
}

int solve(int cur, int left, int right)
{
    if(cur >= steps.size()) return 0;

    if(dp[cur][left][right] != INF) return dp[cur][left][right];

    int now = steps[cur];
    int leftChanged = now == right ? INF : solve(cur+1, now, right) + move(left, now);
    int rightChanged = now == left ? INF : solve(cur+1, left, now) + move(right, now);
    return dp[cur][left][right] = min(leftChanged, rightChanged);
}

int main()
{
    init();

    while(1)
    {
        int val;
        cin>>val;
        if(!val)    break;
        steps.push_back(val);
    }

    cout<<solve(0, 0, 0);
}