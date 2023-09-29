#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P
{
    int x, y;
    bool operator<=(P const& p2)
    {
        if(x == p2.x)
        {
            return y <= p2.y;
        }
        return x <= p2.x;
    }

    P()
    {
        x = 0;
        y = 0;
    }

    P(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
};

int n;
vector<pair<P, P> > lines(3000);
vector<int> root(3000, 0);

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long ccw(P &p1, P &p2, P &p3)
{
    long long s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);

    if(s>0) return 1;
    if(s==0)   return 0;
    return -1;
}

bool isIntersect(pair<P, P>& l1, pair<P, P>& l2)
{
    P p1 = l1.first;
    P p2 = l1.second;
    P p3 = l2.first;
    P p4 = l2.second;

    long long p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    long long p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(p1p2 == 0 && p3p4 == 0)
    {
        if(p2<=p1)   swap(p1, p2);
        if(p4<=p3)   swap(p3, p4);

        return p3<=p2 && p1<=p4;
    }

    return p1p2<=0 && p3p4<=0;
}

int find(int x)
{
    if(root[x] == x)    return x;
    return find(root[x]);
}

void merge(int left, int right)
{
    int l_root = find(left);
    int r_root = find(right);

    int cur = root[l_root];

    for(int i = 0 ; i<n ; i++)
    {
        if(root[i] == cur)
        {
            root[i] = r_root;
        }
    }
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)  root[i] = i;
    
    for(int i = 0 ; i<n ; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        P p1 = P(x1, y1);
        P p2 = P(x2, y2);

        lines[i] = make_pair(p1, p2);
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            if(isIntersect(lines[i], lines[j]))
            {
                merge(i, j);
            }
        }
    }

    vector<int> ans(3000, 0);

    for(int i = 0 ; i<n ; i++)
    {
        ans[find(i)]++;
    }

    int answer = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(ans[i])
        {
            answer++;
        }
    }

    cout<<answer<<'\n';
    cout<<*max_element(ans.begin(), ans.end());
}