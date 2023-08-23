#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <climits>

namespace std
{
    template <>
    struct hash<pair<int, int> > 
    {
        size_t operator()(const pair<int, int>& p) const
        {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}

using namespace std;

vector<vector<int> > map(50, vector<int>(50, 0));
vector<vector<int> > dp(13, vector<int>(100, 0));
unordered_map<pair<int, int>, int> um;
int n, m;
int h = 0, c = 0;
vector<pair<int, int> > shops;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs(int cur)
{
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(n, false));

    q.push(shops[cur]);
    visited[shops[cur].first][shops[cur].second] = true;

    int cnt = 0;
    while(!q.empty())
    {
        int q_size = q.size();
        for(int k = 0 ; k<q_size ; k++)
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int i = 0 ; i<4 ; i++)
            {
                int tx = cx + dx[i];
                int ty = cy + dy[i];

                if(tx<0 || ty<0 || tx>=n || ty>=n)  continue;

                if(!visited[tx][ty])
                {
                    q.push(make_pair(tx, ty));
                    visited[tx][ty] = true;

                    if(map[tx][ty] == 1)
                    {
                        dp[cur][um.find(make_pair(tx, ty))->second] = cnt+1;
                    }
                }
            }
        }
        cnt++;
    }
}

int dfs(int cur, int cnt, vector<int> nums)
{
    if(cnt==0)
    {
        return accumulate(nums.begin(), nums.end(), 0);
    }

    if(c-cur < cnt-1)   return INT_MAX;

    int ans = INT_MAX;

    for(int i = cur ; i<c ; i++)
    {
        vector<int> temp;
        for(int j = 0 ; j<h ; j++)
        {
            temp.push_back(min(nums[j], dp[i][j]));
        }
        ans = min(ans, dfs(i+1, cnt-1, temp));
    }

    return ans;
}

int main()
{
    init();

    cin>>n>>m;

    int index = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 1)
            {
                h++;
                um.insert(make_pair(make_pair(i, j), index++));
            }
            else if(map[i][j] == 2)
            {
                c++;
                shops.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0 ; i<c ; i++)
    {
        bfs(i);
    }

    if(m==c)
    {
        int ans = 0;
        for(int i = 0 ; i<h ; i++)
        {
            int temp = INT_MAX;
            for(int j = 0 ; j<c ; j++)
            {
                temp = min(temp, dp[j][i]);
            }
            ans += temp;
        }
        cout<<ans;
        return 0;
    }
    else
    {
        cout<<dfs(0, m, vector<int>(h, INT_MAX));
    }
}