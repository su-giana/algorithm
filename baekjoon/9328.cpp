#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int h, w;
string key;
vector<vector<char> > building;
vector<vector<bool> > visited;
vector<vector<pair<int, int> > > stored(26, vector<pair<int, int> > ());
vector<bool> isExist(26, false);
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};


void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bfs(int x, int y)
{
    queue<pair<int, int> > q;
    int ans = 0;
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(building[cx][cy] == '*') 
        {
            continue;
        }
        else if(building[cx][cy] >= 'a' && building[cx][cy] <= 'z')
        {
            if(isExist[building[cx][cy] - 'a'] == false)
            {
                int v_size = stored[building[cx][cy] - 'a'].size();
                for(int i = 0 ; i<v_size ; i++)
                {
                    q.push(stored[building[cx][cy] - 'a'][i]);
                }
                isExist[building[cx][cy] - 'a'] = true;
            }
        }
        else if(building[cx][cy] >= 'A' && building[cx][cy] <= 'Z')
        {
            if(!isExist[building[cx][cy] - 'A'])
            {
                stored[building[cx][cy] - 'A'].push_back(make_pair(cx, cy));
                continue;
            }
        }
        else if(building[cx][cy] == '$')
        {
            ans++;
        }

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];

            if(tx<0 || ty<0 || tx>=h || ty>=w)  continue;

            if(!visited[tx][ty])
            {
                q.push(make_pair(tx, ty));
                visited[tx][ty] = true;
            }
        }
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    vector<int> answer;

    while(t--)
    {
        cin>>h>>w;

        building = vector<vector<char> >(h, vector<char>(w, ' '));
        visited = vector<vector<bool> >(h, vector<bool>(w, false));
        isExist = vector<bool>(26, false);
        stored = vector<vector<pair<int, int> > >(26, vector<pair<int, int> >());
        
        for(int i = 0 ; i<h ; i++)
        {
            string s;
            cin>>s;
            for(int j = 0 ; j<w ; j++)
            {
                building[i][j] = s[j];
            }
        }

        cin>>key;

        key = key == "0" ? "" : key;

        for(int i = 0 ; i<key.length() ; i++)
        {
            isExist[key[i] - 'a'] = true;
        }

        int ans = 0;

        for(int i = 0 ; i<h ; i++)
        {
            for(int j = 0 ; j<w ; j++)
            {
                if(i==0 || j==0 || i == h-1 || j == w-1)
                {
                    if(!visited[i][j] && building[i][j] != '*')
                        ans += bfs(i, j);
                }
            }
        }

        cout<<ans<<'\n';
        answer.push_back(ans);

        building.clear();
        isExist.clear();
        stored.clear();
        visited.clear();
    }
}