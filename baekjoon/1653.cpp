#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>

using namespace std;

int n;
vector<int> weights(10, 0);
long long num = 0;
vector<vector<vector<int> > >dp(2, vector<vector<int> >(100000, vector<int>(0)));
set<int> s;
int k;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

pair<int, int> getWeight()
{
    int ans1 = 0;
    int ans2 = 0;
    int val = num;
    for(int i = 1 ; i<=5 ; i++)
    {
        ans1 += val%10 * (6-i);
        ans2 += val%10 * i;
        val /= 10;
    }

    return make_pair(ans1, ans2);
}

void dfs(int visited)
{
    if(s.find(num) != s.end())
    {
        return;
    }

    pair<int, int> weight = getWeight();
    dp[0][weight.first].push_back(num);
    dp[1][weight.second].push_back(num);
    s.insert(num);

    if(visited == (1<<(n+1))-1)
    {
        return;
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!(visited & (1<<i)))
        {
            visited |= (1<<i);
            for(int j = 0 ; j<5 ; j++)
            {
                if(num% (int)pow(10, j+1) == 0)
                {
                    num += weights[i] * pow(10, j);
                    dfs(visited);
                    num -= weights[i] * pow(10, j);
                }
            }
            visited &= ~(1<<i);
        }
    }
}

bool isJoint(int a, int b)
{
    long long bitmask = 0;
    for(int i = 1 ; i<=5 ; i++)
    {
        if(a%10)
        {
            bitmask |= (1<<(a % 10));
        }
        a/=10;
    }

    for(int i = 1 ; i<=5 ; i++)
    {
        if(b%10 && bitmask & (1<<(b % 10)))
        {
            return true;
        }
        b/=10;
    }
    return false;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int weight;
        cin>>weight;
        weights[i] = weight;
    }

    cin>>k;

    dfs(0);

    vector<long long> ans;
    for(int i = 0 ; i<100000 ; i++)
    {
        int l_size = dp[0][i].size();
        int r_size = dp[1][i].size();

        for(int j = 0 ; j<l_size ; j++)
        {
            for(int k = 0 ; k<r_size ; k++)
            {
                if(!isJoint(dp[0][i][j], dp[1][i][k]))
                {
                    long long tmp = dp[0][i][j]+ dp[1][i][k] * 100000ll;
                    ans.push_back(tmp);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    long long answer = k<ans.size() ? ans[k] : ans[ans.size()-1];
    cout<<answer;
}