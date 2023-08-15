#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<string> mbtis;
unordered_map<string, int> s;
int n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getEachDistance(string a, string b)
{
    int score = 0;
    for(int i = 0 ; i<4 ; i++)
    {
        if(a[i]!=b[i])
            score++;
    }

    return score;
}

int getAllDistance(string a, string b, string c)
{
    return getEachDistance(a, b) + getEachDistance(b, c) + getEachDistance(a,c);
}

int solve()
{
    int ans = INT_MAX;

    n = mbtis.size();
    for(int k = 0 ; k<n ; k++)
    {
        for(int i = 0 ; i<n ; i++)
        {
            if(i==k)    continue;

            for(int j = 0 ; j<n ; j++)
            {
                if(i==j || j==k)    continue;

                ans = min(ans, getAllDistance(mbtis[k], mbtis[i], mbtis[j]));
            }
        }
    }

    return ans;
}

int main()
{
    init();

    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        
        for(int i = 0 ; i<n ; i++)
        {
            string mbti;
            cin>>mbti;
            if(s.find(mbti)==s.end())
            {
                mbtis.push_back(mbti);
                s.insert(make_pair(mbti, 1));
            }
            else if(s[mbti]<3)
            {
                s[mbti]++;
                mbtis.push_back(mbti);
            }
        }

        cout<<solve()<<'\n';
        mbtis.clear();
        s.clear();
    }
    
    return 0;
}