#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getVV(vector<vector<int> >& square, int v1, int v2)
{
    long long top = 0, mid = 0, bot = 0;
    int n = square.size();
    int m = square[0].size();

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(j<v1)        top += square[i][j];
            else if(j<v2)   mid += square[i][j];
            else            bot += square[i][j];
        }
    }

    return top*mid*bot;
}

long long getHH(vector<vector<int> >& square, int h1, int h2)
{
    long long top = 0, mid = 0, bot = 0;
    int n = square.size();
    int m = square[0].size();

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(i<h1)        top += square[i][j];
            else if(i<h2)   mid += square[i][j];
            else            bot += square[i][j];
        }
    }

    return top*mid*bot;
}

long long getVH(vector<vector<int> >& square, int h, int v)
{
    long long lu = 0, ld = 0, ru = 0, rd = 0;
    int n = square.size();
    int m = square[0].size();

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(i<h && j<v)          lu+=square[i][j];
            else if(i>=h && j<v)    ld += square[i][j];
            else if(i<h && j>=v)    ru += square[i][j];
            else                    rd += square[i][j];
        }
    }

    long long sec_1 = max((lu + ld) * ru * rd, lu * ld * (ru + rd));
    long long sec_2 = max((ld + rd) * lu * ru, ld * rd * (lu + ru));
    return max(sec_1, sec_2);
}

long long getMaxPro(vector<vector<int> >& square)
{
    int n = square.size();
    int m = square[0].size();

    long long maxPro = 0;
    for(int i = 1 ; i<n ; i++)
    {
        for(int j = 1 ; j<m ; j++)
        {
            maxPro = max(maxPro, getVH(square, i, j));
        }
    }

    for(int i = 1 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            maxPro = max(maxPro, getHH(square, i, j));
        }
    }

    for(int i = 1 ; i<m ; i++)
    {
        for(int j = i+1 ; j<m ; j++)
        {
            maxPro = max(maxPro, getVV(square, i, j));
        }
    }

    return maxPro;
}

int main()
{
    init();

    int n, m;
    cin>>n>>m;

    vector<vector<int> > square(n, vector<int>(m, 0));
    for(int i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(int j = 0 ; j<m ; j++)
        {
            square[i][j] = s[j]-'0';
        }
    }

    cout<<getMaxPro(square);
}