#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getPathCnt(vector<vector<char> >& board)
{
    int n = board.size();
    int m = board[0].size();

    
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

    cout<<getPathCnt(board);
}