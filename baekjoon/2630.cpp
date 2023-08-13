#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > paper(128, vector<int>(128, 0));
int n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

pair<int, int> getPaper(int n, int x, int y)
{
    if(n==1 && paper[x][y])    return make_pair(1, 0);
    else if(n==1 && !paper[x][y])   return make_pair(0, 1);

    bool isWhite = true;
    bool isBlue = true;
    for(int i = x ; i<x+n ; i++)
    {
        for(int j = y ; j<y+n ; j++)
        {
            if(!paper[i][j])
                isBlue = false;
            else
                isWhite = false;
        }
    }

    if(isBlue)   return make_pair(1, 0);
    if(isWhite)  return make_pair(0, 1);

    int div = n/2;
    pair<int, int> ans;
    ans.first += getPaper(div, x, y).first + getPaper(div, x + div, y).first + getPaper(div, x, y+div).first + getPaper(div, x+div, y+div).first;
    ans.second += getPaper(div, x, y).second + getPaper(div, x + div, y).second + getPaper(div, x, y+div).second + getPaper(div, x+div, y+div).second;
    return ans;
}

int main()
{
    init();

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>paper[i][j];
        }
    }

    pair<int, int> ans = getPaper(n, 0, 0);
    cout<<ans.second<<'\n'<<ans.first;
}