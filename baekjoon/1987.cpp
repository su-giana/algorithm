#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int maxLen = 0;

void dfs(vector<vector<char> >& alpha, vector<bool>& visited, int x, int y, int cnt)
{
    int n = alpha.size();
    int m = alpha[0].size();
    maxLen = max(maxLen, cnt);

    for(int i = 0 ; i<4 ; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if(tx<0 || tx>=n || ty<0 || ty>=m)  continue;
        if(!visited[alpha[tx][ty] - 'A'])
        {
            visited[alpha[tx][ty] - 'A'] = true;
            dfs(alpha, visited, tx, ty, cnt+1);
            visited[alpha[tx][ty] - 'A'] = false;
        }
    }
}

int main()
{
    init();

    int n, m;
    cin>>n>>m;
    vector<vector<char> > alpha(n, vector<char>(m, 0));
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            alpha[i][j] = s[j];
        }
    }
    vector<bool> visited(26, false);
    visited[alpha[0][0] - 'A'] = true;

    dfs(alpha, visited, 0, 0, 1);
    cout<<maxLen;
}