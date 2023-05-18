#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getMinMove(string puzzle)
{
    deque<string> q;
    unordered_map<string, int> cntMove;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    q.push_back(puzzle);
    cntMove.insert(make_pair(puzzle, 0));

    while(!q.empty())
    {
        string cur = q.front();
        q.pop_front();
        int curMove = cntMove[cur];
        int blank = cur.find('0');
        int x = blank % 3;
        int y = blank / 3;

        if(cur == "123456780")  return curMove;

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || tx>=3 || ty<0 || ty>=3)  continue;
            int swap = tx + ty*3;

            string next = cur;
            next[swap] = cur[blank];
            next[blank] = cur[swap];

            if(cntMove.count(next) == 0)
            {
                cntMove.insert(make_pair(next, curMove+1));
                q.push_back(next);
            }   
        }
    }

    return -1;
}

int main()
{
    init();

    string puzzle;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            string num;
            cin>>num;
            puzzle = puzzle + num;
        }
    }

    cout<<getMinMove(puzzle);
}