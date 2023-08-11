#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
vector<vector<int> > graph(100, vector<int>(100, 5051));

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 0 ; i<m ; i++)
    {
        int in, out;
        cin>>in>>out;
        graph[in-1][out-1] = 1;
        graph[out-1][in-1] = 1;
    }

    for(int i = 0 ; i<n ; i++)
    {
        graph[i][i] = 0;
    }

    for(int k = 0 ; k<n ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    int kevin = 0;
    int relation = accumulate(graph[0].begin(), graph[0].end(), 0);
    for(int i = 1 ; i<n ; i++)
    {
        int next = accumulate(graph[i].begin(), graph[i].end(), 0);
        if(relation > next)
        {
            kevin = i;
            relation = next;
        }
    }
    cout<<kevin+1;
}