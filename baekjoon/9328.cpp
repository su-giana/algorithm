#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
vector<vector<char> > map(100, vector<char>(100, ' '));
vector<vector<bool> > visited(100, vector<bool>(100, false));
vector<string> dollors;
string key;
vector<vector<int> > vertice(26, vector<int>());
vector<bool> isPos(26, false);
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void topology_sort()
{
    if(key == "0")  return;

    int k_size = key.size();
    queue<int> q;
    vector<bool> visited_(26, false);
    for(int i = 0 ; i<k_size ; i++)
    {
        q.push(key[i] - 'a');
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        isPos[cur] = true;

        int v_size = vertice[cur].size();
        for(int i = 0 ; i<v_size ; i++)
        {
            int next = vertice[cur][i];

            if(!visited_[next])
            {
                visited_[next] = true;
                q.push(next);
            }
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<pair<int, int>, string> > q;
    
    q.push(make_pair(make_pair(x, y), ""));
    visited[x][y] = true;

    while(!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        string keys = q.front().second;
        q.pop();

        if(map[cx][cy] == '*')
        {
            continue;
        }
        else if(map[cx][cy] == '$')
        {
            dollors.push_back(keys);
        }
        else if(map[cx][cy] >= 'a' && map[cx][cy] <= 'z')
        {
            if(keys.size() == 0)
            {
                key += map[cx][cy];
            }
            else
            {
                vertice[keys[keys.size()-1] - 'A'].push_back(map[cx][cy] - 'a');
            }
        }
        else if(map[cx][cy] >= 'A' && map[cx][cy] <= 'Z')
        {
            keys = keys + map[cx][cy];
        }

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];

            if(tx<0 || tx>=w || ty<0 || ty>=h)  continue;

            if(map[tx][ty] != '*' && !visited[tx][ty])
            {
                visited[tx][ty] = true;
                q.push(make_pair(make_pair(tx, ty), keys));
            }
        }
    }
}

int main()
{
    init();

    int t;
    cin>>t;

    while(t--)
    {
        cin>>w>>h;

        dollors = {};
        isPos.resize(26, false);
        vertice.resize(26, vector<int>());
        visited.resize(100, vector<bool>(100, false));

        for(int i = 0 ; i<w ; i++)
        {
            string s;
            cin>>s;

            for(int j = 0 ; j<h ; j++)
            {
                map[i][j] = s[j];
            }
        }

        cin>>key;

        for(int i = 0 ; i<w ; i++)
        {
            for(int j = 0 ; j<h ; j++)
            {
                if((i== 0 || j==0 || i==w-1 || j==h-1) && !visited[i][j] && map[i][j] != '*')
                {
                    bfs(i, j);
                }
            }
        }

        topology_sort();

        int ans = 0;

        int d_size = dollors.size();
        for(int i = 0 ; i<d_size ; i++)
        {
            bool isValid = true;
            for(int j = 0 ; j<dollors[i].length() ; j++)
            {
                if(!isPos[dollors[i][j] - 'A'])
                {
                    isValid = false;
                }
            }
            if(isValid) ans++;
        }

        cout<<ans<<'\n';
    }
}