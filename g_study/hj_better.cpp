#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <climits>

using namespace std;

vector<int> order;

vector<vector<pair<int, int> > > floyd_war(vector<vector<pair<int, int> > > graph, int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            for(int k = 0 ; k<n; k++)
            {
                if(graph[i][j].first >  graph[i][k].first + graph[k][j].first)
                {
                    graph[i][j].first = graph[i][k].first + graph[k][j].first;
                    graph[i][j].second = k;
                }
            }
        }
    }
    return graph;
}

void answer(vector<vector<pair<int, int> > > map, int x, int candid)
{

    if(x==0)
    {
        return;
    }
    
    order.push_back(x);
    answer(map, map[candid][x].second, candid);
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int> > > map(n, vector<pair<int, int> >(n, make_pair(10001, 0)));
    for(int i = 0 ; i<n ; i++)
    {
        map[i][i].first = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;  // 간선의 시작점, 끝점, 가중치
        cin >> from >> to >> cost;

        map[from][to].first = cost;
        map[to][from].first = cost;
    }

    map = floyd_war(map, n);

    for(int i = 0 ; i<map.size() ; i++)
    {
        for(int j = 0 ; j<map[i].size() ; j++)
        {
            cout<<map[i][j].second<<" ";
        }
        cout<<endl;
    }

    vector<int> costs(n, INT_MAX);

    for(int i = 0 ; i<costs.size() ; i++)
    {
        for(int j = 0 ; j<map[i].size() ; j++)
        {
            costs[i] += map[i][j].first;
        }
    }

    int candid = min_element(costs.begin(), costs.end()) - costs.begin();

    cout<<candid<<endl;

    for(int i = 1 ; i<map.size() ; i++)
    {
        order.clear();

        answer(map, map[candid][i].second, candid);
        order.push_back(i);
        reverse(order.begin(), order.end());
        order.push_back(candid);

        for(int i = 0 ; i<order.size() ; i++)
        {
            cout<<order[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}