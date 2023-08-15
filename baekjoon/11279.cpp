#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int n;
    cin>>n;

    priority_queue<int> q;

    while(n--)
    {
        int val;
        cin>>val;

        if(val!=0)
        {
            q.push(val);
        }
        else
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
    }
}