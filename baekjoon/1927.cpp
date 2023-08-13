#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n;
    cin>>n;

    while(n--)
    {
        int cmd;
        cin>>cmd;
        
        if(cmd==0)
        {
            if(q.empty())
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<q.top()<<'\n';
                q.pop();
            }
        }
        else
        {
            q.push(cmd);
        }
    }
}