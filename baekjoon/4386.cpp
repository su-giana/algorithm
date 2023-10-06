#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<pair<double, double> > stars(100, make_pair(0, 0));
vector<int> root(1001, 0);
vector<pair<int, int> > vertice;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

double getDis(pair<int, int>& star)
{
    double dx = (stars[star.first].first - stars[star.second].first)
        * (stars[star.first].first - stars[star.second].first);
    double dy = (stars[star.first].second - stars[star.second].second)
        * (stars[star.first].second - stars[star.second].second);
    return sqrt(dx + dy);
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    double gapA = getDis(a);
    double gapB = getDis(b);
    return gapA < gapB;
}

int find(int cur)
{
    if(cur == root[cur])    return cur;
    return root[cur] = find(root[cur]);
}

void merge(int star1, int star2)
{
    int left = find(star1);
    int right = find(star2);

    root[left] = right;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        root[i] = i;
    }

    for(int i = 0 ; i<n ; i++)
    {
        cin>>stars[i].first>>stars[i].second;
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            vertice.push_back(make_pair(i, j));
        }
    }

    sort(vertice.begin() ,vertice.end(), cmp);

    double ans = 0;

    int m = vertice.size();
    for(int i = 0 ; i<m ; i++)
    {
        int left = vertice[i].first;
        int right = vertice[i].second;

        if(find(left) == find(right))   continue;

        merge(left, right);
        ans += getDis(vertice[i]);
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ans;
}