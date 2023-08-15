#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> map;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<string> split(string s)
{
    string tmp;
    stringstream ss(s);
    vector<string> answer;
    while(getline(ss, tmp, ' '))
    {
        answer.push_back(tmp);
    }
    return answer;
}

int main()
{
    int n, m;
    cin>>n>>m;

    while(n--)
    {
        string s;
        cin>>s;
        string ps;
        cin>>ps;

        map.insert(make_pair(s, ps));
    }

    while(m--)
    {
        string s;
        cin>>s;
        cout<<map[s]<<'\n';
    }
}