#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, t;
vector<vector<int>> stars;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getDistance(int day)
{
    long long answer = 0;
    
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            long long x1 = stars[i][0] + day * stars[i][2];
            long long y1 = stars[i][1] + day * stars[i][3];
            long long x2 = stars[j][0] + day * stars[j][2];
            long long y2 = stars[j][1] + day * stars[j][3];

            long long dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

            answer = max(answer, dis);
        }
    }

    return answer;
}

pair<int, long long> ternarySearch()
{
    int a = 0;
    int b = t;

    while(b-a>=3)
    {
        int ta = (2*a + b)/3;
        int tb = (a + 2*b)/3;
        long long da = getDistance(ta);
        long long db = getDistance(tb);

        if(da <= db)
        {
            b = tb;
        }
        else if(da > db)
        {
            a = ta;
        }
    }

    pair<int, long long> ans = make_pair(a, getDistance(a));
    if(a+1<=t && getDistance(a+1) < ans.second)
        ans = make_pair(a+1, getDistance(a+1));
    if(a+2<=t && getDistance(a+2) < ans.second)
        ans = make_pair(a+2, getDistance(a+2));

    return ans;
}

int main()
{
    cin>>n>>t;

    for(int i = 0 ; i < n ; i++)
    {
        int x, y, dx, dy;
        cin>>x>>y>>dx>>dy;

        vector<int> star = {x, y, dx, dy};

        stars.push_back(star);
    }

    pair<int, long long> ans = ternarySearch();

    cout<<ans.first<<endl<<ans.second;
}