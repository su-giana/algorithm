#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<string> names(100001, "");
unordered_map<string, int> num;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    cin>>n>>m;

    for(int i = 1 ; i<=n ; i++)
    {
        string name;
        cin>>name;
        names[i] = name;
        num.insert(make_pair(name, i));
    }

    for(int i = 0 ; i<m ; i++)
    {
        string s;
        cin>>s;
        
        if(num.find(s) == num.end())
        {
            cout<<names[stoi(s)]<<'\n';
        }
        else
        {
            cout<<num[s]<<'\n';
        }
    }
}