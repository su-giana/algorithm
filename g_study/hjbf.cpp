#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int> > dijkstra(int start, int n, vector<pair<int, int> >graph[])
{
    vector<pair<int, int> > dist(n, make_pair(0, INT_MAX));   // list to store minimum path
    priority_queue<pair<int, int> > pq;

    dist[start].second = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty())
    {
        int cur_dist = -pq.top().first; // 큐에서 꺼내 방문하고 있는 정점의 거리
        int cur_node = pq.top().second;  // 정점의 인덱스(번호)
        pq.pop();

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int nxt_node = graph[cur_node][i].first;  // 인접 정점 번호
            int nxt_dist = cur_dist + graph[cur_node][i].second;  // 인접 정점까지 거리

            if (nxt_dist < dist[nxt_node].second)  // 지금 계산한 것이 기존 거리값보다 작다면
            {
                dist[nxt_node].first = cur_node;
                dist[nxt_node].second = nxt_dist;  // 거리값 업데이트
                pq.push(make_pair( -nxt_dist, nxt_node ));  // 우선순위 큐에 넣기
            }
        }
    }

    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
} 

vector<int> answer(vector<int>& order, int x, vector<pair<int, int> >& dist)
{
    if(x==0)
        return order;

    order.push_back(x);
    return answer(order, dist[x].first, dist);
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> > graph[n];

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;  // 간선의 시작점, 끝점, 가중치
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair( to, cost ));  // 무향 그래프라 가정하므로 시작점과 끝점 둘 다 벡터에 넣어야 함
        graph[to].push_back(make_pair( from, cost ));
    }
    
    int candid = INT_MAX;
    int cost = INT_MAX;
     for(int i = 0 ; i<n ; i++)
    {
        int temp = 0;
        vector<pair<int, int> > dist = dijkstra(i, n, graph);

        

         for(int i=0 ; i<dist.size() ; i++)
        {
            temp += dist[i].second;
        }

        if(cost>temp)
        {
            candid = i;
            cost = temp;
        } 
    } 

    cout<<candid<<endl;

    vector<pair<int, int> > dist = dijkstra(candid, n, graph);

    for(int i=1 ; i<dist.size() ; i++)
    {

        vector<int> order;
        vector<int> sol =  answer(order, i, dist);


        reverse(sol.begin(), sol.end());

        for(int i = 0 ; i<sol.size() ; i++)
            cout<<sol[i]<<" ";
        cout<<endl;
    } 
    
    
    return 0;
}