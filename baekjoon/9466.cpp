#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

vector<int> students(100001, 0);
int visitOrder = 1;
int answer = 0;
int depth = 1;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void dfs(vector<int>& arr, vector<int>& visited, vector<bool>& finished, int cur)
{
    visited[cur] = visitOrder++;

    int next = arr[cur];
    if(visited[next] == -1)
    {
        dfs(arr, visited, finished, next);
    }
    else if(!finished[next])
    {
        answer += visited[cur] - visited[next] + 1;
    }

    finished[cur] = true;
}

int main()
{
    init();

    int t;
    cin>>t;
    
    while(t--)
    {
        answer = 0;
        visitOrder = 0;
        int n;
        cin>>n;
        vector<int> arr(n+1, 0);
        for(int i = 1 ; i<=n ; i++)
        {
            int num;
            cin>>num;
            arr[i] = num;
        }
        vector<int> visited(n+1, -1);
        vector<bool> finished(n+1, false);

        for(int i = 1 ; i<=n ; i++)
        {
            if(!finished[i])
            {
                dfs(arr, visited, finished, i);
            }
        }
        cout<<n - answer<<'\n';
    }
}