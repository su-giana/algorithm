#include <iostream>
#include <vector>

using namespace std;

string getQuardTree(vector<vector<char> >& video, long long n, long long x, long long y)
{
    if(n==1)
    {
        string s(1, video[x][y]);
        return s;
    }

    string s = "";
    long long div = n/2;
    for(long long i = 0 ; i<n ; i += div)
    {
        for(long long j = 0 ; j<n ; j += div)
        {
            string quardTree = getQuardTree(video, div, x + i, y + j);
            s += quardTree;
        }
    }

    if(s == "0000") return "0";
    if(s == "1111") return "1";
    return "(" + s + ")";
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();
    long long n;
    cin>>n;

    vector<vector<char> > video(n, vector<char>(n, 0));
    for(long long i = 0 ; i<n ; i++)
    {
        string s;
        cin>>s;
        for(long long j = 0 ; j<n ; j++)
        {
            video[i][j] = s[j];
        }
    }

    string s = getQuardTree(video, n, 0, 0);
    cout<<s;
}