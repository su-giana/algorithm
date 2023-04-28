#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

vector<int> students(100001, 0);

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void dfs(vector<vector<int> >& vertices, vector<bool>& visited, int vertex)
{
    int n = vertices.size();

    queue<int> que;
    stack<int> st;
    que.push(vertex);
    vector<bool> Nvisited(n, false);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        if(Nvisited[cur])   continue;
        Nvisited[cur] = true;
        visited[cur] = true;
        st.push(cur);

        n = vertices[cur].size();
        for(int i = 0 ; i<n ; i++)
        {
            int next = vertices[cur][i];
            if(!Nvisited[next])
            {
                que.push(next);
            }
            else
            {
                while(!st.empty() && st.top() != next)
                {
                    students[st.top()] = 1;
                    st.pop();
                }
                students[st.top()] = 1;
                st.pop();
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    
    for( ; t>0 ; t--)
    {
        int n;
        cin>>n;

        vector<vector<int> > vertices(n+1, vector<int>());
        for(int i = 1 ; i<=n ; i++)
        {
            int selected;
            cin>>selected;

            vertices[i].push_back(selected);
        }

        vector<bool> visited(n+1, false);

        for(int i = 1 ; i<=n ; i++)
        {
            if(!visited[i])
            {
                dfs(vertices, visited, i);
            }       
        }

        cout<<n - accumulate(students.begin()+1, students.begin() + n + 1, 0)<<endl;
    }
}