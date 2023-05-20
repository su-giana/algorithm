#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


int getPathCnt(vector<vector<char> >& board, vector<vector<int> >& checker, int x, int y, int k, string ans, int pos)
{
    int n = board.size();
    int m = board[0].size();
    int len = ans.length();
    int cnt = 0;

    if(pos == len)  return 1;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    for(int i = k ; i>0 ; i--)
    {
        for(int j = 0 ; j<4 ; j++)
        {
            int tx = x + dx[j]*i;
            int ty = y + dy[j]*i;
                
            if(tx<0 || tx>=n || ty<0 || ty>=m)  continue;
            if(ans[pos] == board[tx][ty])
            {
                if(checker[tx][ty]==-1)
                {
                    checker[tx][ty] = getPathCnt(board, checker, tx, ty, k, ans, pos+1);
                }
                checker[x][y] += checker[tx][ty];
            }
        }
    }

    return checker[x][y];
}

int getAns(vector<vector<char> >& board, string ans, int k)
{
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    vector<vector<int> > checker(n, vector<int>(m, -1));


    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(board[i][j] == ans[0])
            {
                checker[i][j] = 0;
                cnt += getPathCnt(board, checker, i, j, k, ans, 1);
            }
        }
    }

    return cnt;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<char> > board(n, vector<char>(m, ' '));
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            board[i][j] = s[j];
        }
    }
    string ans;
    cin>>ans;

    cout<<getAns(board, ans, k);
}