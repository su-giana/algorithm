#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map(9, vector<int>(9, 0));
vector<vector<int> > ans(9, vector<int>(9, 0));

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getPos(int x, int y)
{
    int ans = (1<<10) - 1;
    for(int i = 0 ; i<9 ; i++)
    {
        if(map[x][i])   ans &= ~(1<<map[x][i]);
        if(map[i][y])   ans &= ~(1<<map[i][y]);
    }

    for(int i = (x/3) * 3 ; i < (x/3 + 1) * 3 ; i++)
    {
        for(int j = (y/3) * 3 ; j< (y/3 + 1) * 3 ; j++)
        {
            if(map[i][j])   ans &= ~(1<<map[i][j]);
        }
    }

    return ans;
}

bool dfs(int x, int y)
{
    for(int i = 0 ; i<9 ; i++)
    {
        for(int j = 0 ; j<9 ; j++)
        {
            if(map[i][j] == 0)
            {
                int pos = getPos(i, j);

                if(pos == 1)
                {
                    return false;
                }

                while(true)
                {
                    bool isAllFalse = true;

                    for(int k = 1 ; k<=9 ; k++)
                    {
                        if(pos & (1<<k))
                        {
                            map[i][j] = k;
                            if(dfs(i, j))
                            {
                                isAllFalse = false;
                                return true;
                            }
                        }
                    }

                    if(isAllFalse)
                    {
                        map[i][j] = 0;

                        int n_pos = getPos(i, j);
                        if(pos != n_pos && n_pos != 1)
                        {
                            pos = getPos(i, j);
                            continue;
                        }

                        return false;
                    }
                }
            }
        }
    }

    ans = map;
    return true;
}

int main()
{
    init();

    for(int i = 0 ; i<9 ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<9 ; j++)
            map[i][j] = s[j] - '0';
    }

    dfs(0, 0);

    for(int i = 0 ; i<9 ; i++)
    {
        for(int j = 0 ; j<9 ; j++)  cout<<ans[i][j];
        cout<<'\n';
    }
}