#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<vector<int> > tr(500, vector<int>(500, 0));
unordered_map<string, int> map;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int divAndCon(int r, int c)
{
    if(r == n)
    {
        return 0;
    }

    string n = to_string(r) + " " + to_string(c);
    string l = to_string(r+1) + " " + to_string(c);
    string ri = to_string(r+1) + " " + to_string(c+1);
    
    int left = map.find(l) == map.end() ? divAndCon(r+1, c) : map[l];
    int right = map.find(ri) == map.end() ? divAndCon(r+1, c+1) : map[ri];
    map.insert(make_pair(n, tr[r][c] + max(left, right)));
    
    return tr[r][c] + max(left, right);
}

int main()
{
    init();

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            cin>>tr[i][j];
        }
    }

    cout<<divAndCon(0, 0);
}