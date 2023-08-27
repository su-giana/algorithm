#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int n, se;
vector<int> nums(40, 0);
unordered_map<int, int> um;
long long ans = 0;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void leftSide(int cur, int acc)
{
    if(cur == n/2)
    {
        um[acc]++;
        return;
    }

    leftSide(cur+1, acc);
    leftSide(cur+1, acc + nums[cur]);
}

void rightSide(int cur, int acc)
{
    if(cur == n)
    {
        ans += um[se - acc];
        return;
    }

    rightSide(cur+1, acc);
    rightSide(cur+1, acc + nums[cur]);
}

int main()
{
    init();

    cin>>n>>se;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    leftSide(0, 0);
    rightSide(n/2, 0);

    if(se == 0)
        cout<<ans-1;
    else
        cout<<ans;
}