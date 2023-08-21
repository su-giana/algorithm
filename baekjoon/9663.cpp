#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > queens;
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool enableQueen(int x, int y)
{
    for(pair<int, int> queen : queens)
    {
        if(x == queen.first)
        {
            return false;
        }
        else if(y == queen.second)
        {
            return false;
        }
        else if(abs(x - queen.first) == abs(y - queen.second))
        {
            return false;
        }
    }
    return true;
}

int dfs(int cur)
{
    if(cur == n)
    {
        return 1;
    }

    int ans = 0;
    for(int j = 0 ; j<n ; j++)
    {
        if(enableQueen(cur, j))
        {
            queens.push_back(make_pair(cur, j));

            ans += dfs(cur+1);

            queens.pop_back();
        }
    }

    return ans;
}

int main()
{
    init();

    cin>>n;

    cout<<dfs(0);
}