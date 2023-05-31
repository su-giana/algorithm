#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int n = 100001;
vector<int> Tree(4*n);

bool compare(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0])	return a[1]<b[1];
    return a[0]>b[0];
}

void pushTree(int node, int begin, int end, int y)
{
    Tree[node] = 1;
    if(begin==end)
    {   
        return;
    }
    
    int mid = begin + (end - begin)/2;
    if(y<=mid)	pushTree(2*node, begin, mid, y);
    else		pushTree(2*node+1, mid+1, end, y);
}

void pushY(int y)
{
    pushTree(1, 0, n, y);
}

bool isInRange(int begin, int end, int node, int limit)
{
    if(limit<=begin)	return Tree[node];
    else if(limit > end)	return false;
    
    int mid = begin + (end - begin) / 2;
    
    return isInRange(begin, mid, 2*node, limit) || isInRange(mid+1, end, 2*node+1, limit);

}

bool getIncentive(int y)
{
    return !isInRange(0, n, 1, y+1);
}

int solution(vector<vector<int>> scores) 
{
	pair<int, int> wanho = make_pair(scores[0][0], scores[0][1]);
    priority_queue<pair<int, pair<int, int> > > q;
    vector<bool> visited(n+1, 0);
    
    sort(scores.begin(), scores.end(), compare);
    q.push(make_pair(scores[0][0] + scores[0][1], make_pair(scores[0][0], scores[0][1])));
	pushY(scores[0][1]);
    visited[scores[0][0]] = true;
    
    int n = scores.size();
    for(int i = 1 ; i<n ; i++)
    {   
        if(getIncentive(scores[i][1]))
        {
            visited[scores[i][0]] = true;
            q.push(make_pair(scores[i][0] + scores[i][1], make_pair(scores[i][0], scores[i][1])));
        }
        pushY(scores[i][1]);
    }
    
    unordered_map<int, int> map;
    int cnt = 1;
    while(!q.empty())
    {
        pair<int, int> cur = q.top().second;
        int weight = q.top().first;
        q.pop();
        
		if(map.find(weight) == map.end())
        {
            map.insert(make_pair(weight, cnt));
        }
        if(cur.first == wanho.first && cur.second==wanho.second)	return map[weight];
        cnt++;
    }
    
    return -1;
}