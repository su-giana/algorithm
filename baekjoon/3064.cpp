#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {0, 0, -1, 1, 1, -1, 1, -1};
vector<int> dy = {1, -1, 0, 0, -1, 1, 1, -1};


int getValue(vector<vector<char> >& map, int i, int j)
{
    int n = map.size();
    if(i<0 || j<0 || i>=n || j>=n)  return 1;
    if(map[i][j] == '#' || map[i][j] == '*' || map[i][j] == 'o')    return 1;

    return map[i][j];
}

void dfs(vector<vector<char> >&map, int i, int j, int change)
{
    int n = map.size();
    if(i<0 || j<0 || i>=n || j>=n)  return; 

    if(change == -1)
    {
        if(map[i][j] != '#' && map[i][j] != '*' && map[i][j] != 'o' && map[i][j] != '0')
            map[i][j] = map[i][j] - 1;
    }
    else if(change == 0)
    {
        if(map[i][j] == '#')
            map[i][j] = 'o';
    }
}

void dfs(vector<vector<char> >& map, int i, int j)
{
    int n = map.size();
    if((i!=1 && j!=1 && i!=n-2 && j!=n-2) || (i<0 || i>=n || j<0 || j>=n))  return;  

    int test = 1;
    for(int k = 0 ; k<8 ; k++)
    {
        test = test && (getValue(map, i+dx[k], j+dy[k]) != '0');
    }

    if(!test)
    {
        if(map[i][j] == '#')
        {
            map[i][j] = 'o';
        }
    }
    else
    {
        if(map[i][j] == '#')
        {
            map[i][j] = '*';
            for(int k = 0 ; k<8 ; k++)
            {
                dfs(map, i+dx[k], j+dy[k], -1);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        vector<vector<char> > graph(n, vector<char>(n, 0));

        for(int i = 0 ; i<n ; i++)
        {
            string s;
            cin>>s;
            for(int j = 0 ; j<s.length() ; j++)
            {
                graph[i][j] = s[j];
            }
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(i==1 || j==1 || i==n-2 || j==n-2)    dfs(graph, i, j);
            }
        }

        int answer = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(graph[i][j] == '#' || graph[i][j] == '*')
                    answer++;
            }
        }

        cout<<answer<<endl;
    }
}

