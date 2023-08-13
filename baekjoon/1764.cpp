#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
set<string> s;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    cin>>n>>m;
    vector<string> answer;

    while(n--)
    {
        string ss;
        cin>>ss;
        s.insert(ss);
    }

    while(m--)
    {
        string ss;
        cin>>ss;
        if(s.find(ss) != s.end())
        {
            answer.push_back(ss);
        }
    }

    sort(answer.begin(), answer.end());
    int a_size = answer.size();
    cout<<a_size<<'\n';
    for(int i = 0 ; i<a_size ; i++)
    {
        cout<<answer[i]<<'\n';
    }
}