#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <time.h>

using namespace std;

vector<pair<int, int> > cats;
vector<vector<long long> > dp;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long bfs()
{
    int n = cats.size();
    deque<pair<int, int> > q;
    int cnt = 0;
    q.push_back(make_pair(-1, 0));

    while(!q.empty() && cnt<n)
    {
        int m = q.size();
        for(int k = 0 ; k<m ; k++)
        {
            int cur = q.front().first;
            int visited =q.front().second;
            q.pop_front();

            for(int i = 0 ; i<n ; i++)
            {
                if(cur == -1)
                {
                    dp[cnt][i] = cats[i].first + cats[i].second;
                    q.push_back(make_pair(i, (1<<i)));
                }
                else if(!(visited & (1<<i)))
                {
                    long long temp = dp[cnt-1][cur] + abs(cats[cur].first - cats[i].first) + abs(cats[cur].second - cats[i].second);
                    if(temp < dp[cnt][i])
                    {
                        dp[cnt][i] = temp;
                        q.push_back(make_pair(i, visited | (1<<i)));
                    }
                }
            }
        }
        cnt++;
    }

    for(int i = 0 ; i<n ; i++)
    {
        dp[n-1][i] += cats[i].first + cats[i].second;
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

int main()
{
    init();
    int n;
    cin>>n;
    
    for(int i = 0 ; i<n ; i++)
    {
        int x, y;
        cin>>x>>y;
        cats.push_back(make_pair(x, y));
    }

    for(int i = 0 ; i<n ; i++)
    {
        dp.push_back(vector<long long>());
        for(int j = 0 ; j<n ; j++)
        {
            dp[i].push_back(16000001);
        }
    }

    cout<<bfs();
}