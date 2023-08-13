#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>

using namespace std;

int n;
vector<int> weights(10, 0);
vector<int> nums(10, 0);
vector<int> paralle;
set<long long> s;
set<long long> s_visited;
int k;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool isSym()
{
    int left = 0;
    int right = 0;
    for(int i = 0 ; i<10 ; i++)
    {
        if(i<5)
        {
            left += (5 - i) * nums[i];
        }
        else
        {
            right += (i-4) * nums[i];
        }
    }

    return left == right;
}

long long toNum()
{
    long long ans = 0;
    for(int i = 0 ; i<10 ; i++)
    {
        ans += nums[i] * pow(10, 9-i);
    }
    return ans;
}

void store()
{
    long long ans = toNum();
    if(s.find(ans) == s.end())
    {
        s.insert(ans);
        paralle.push_back(ans);
    }
}

void dfs(int visited)
{
    if(s_visited.find(toNum()) != s_visited.end())
    {
        return;
    }

    if(isSym())
    {
        store();
    }
    s_visited.insert(toNum());

    if(visited == 1111111111)
    {
        return;
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(!(visited & (1<<i)))
        {
            visited |= (1<<i);
            for(int j = 0 ; j<10 ; j++)
            {
                if(nums[j] == 0)
                {
                    nums[j] = weights[i];
                    dfs(visited);
                    nums[j] = 0;
                }
            }
            visited &= ~(1<<i);
        }
    }
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

    sort(paralle.begin(), paralle.end());
    long long answer = k<paralle.size() ? paralle[k] : paralle[paralle.size()-1];
    cout<<answer;
}