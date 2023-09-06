#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > map(10, vector<int>(10, 0));
vector<int> tmp;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dfs(int cur)
{
    if(cur >= n*n) return tmp.size();

    int ans = 0;

    for(int i = cur ; i<n*n ; i++)
    {
        if(map[i/n][i%n])
        {
            bool isPos = true;
            int b_size = tmp.size();
            for(int j = 0 ; j<b_size ; j++)
            {
                if(abs(i/n - tmp[j]/n) == abs(i%n - tmp[j]%n))
                {
                    isPos = false;
                    break;
                }
            }

            if(!isPos)  continue;

            tmp.push_back(i);

            ans = max(dfs(i+1), ans);

            tmp.pop_back();

            ans = max(ans, dfs(i+1));

            break;
        }
    }

    int b_size = tmp.size();
    return max(b_size, ans);
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>map[i][j];
        }
    }

    cout<<dfs(0);
}