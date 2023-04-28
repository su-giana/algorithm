#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int dfs(vector<vector<int> >& vertices, vector<bool>& visited, int vertex)
{
    int n = vertices.size();
    queue<int> que;
    vector<int> colors(n, -1);

    colors[vertex] = 0;
    que.push(vertex);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        visited[cur] = true;
//        cout<<"("<<cur<<", "<<colors[cur]<<")"<<endl;

        int n = vertices[cur].size();
        for(int i = 0 ; i<n ; i++)
        {
            int next = vertices[cur][i];
            if(!visited[next])
            {
                que.push(next);
                colors[next] = !(colors[cur]);
            }
            else
            {
                if(colors[next] == colors[cur])
                {
//                    cout<<cur<<" "<<next<<endl;
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    int k;
    cin>>k;

    for(; k>0 ; --k)
    {
        int v, e;
        cin>>v>>e;

        vector<vector<int> > vertices(v+1, vector<int>());
        for(int i = 0 ; i<e ; i++)
        {
            int in, out;
            cin>>in>>out;
            vertices[in].push_back(out);
            vertices[out].push_back(in);
        }
        
        vector<bool> visited(v+1, false);
        for(int i = 1 ; i<=v ; i++)
        {
            if(!visited[i])
            {
                vector<bool> temp(v+1, false);
                if(!dfs(vertices, temp, i))
                {
                    cout<<"NO"<<endl;
                    break;
                }
                for(int j = 1 ; j<=v ; j++)
                {
                    if(!visited[j] && temp[j])
                        visited[j] = temp[j];
                }
            }

            if(i==v)
                cout<<"YES"<<endl;
        }
    }
}