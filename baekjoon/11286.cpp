#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
        {
            return a>b;
        }
        else
        {
            return abs(a) > abs(b);
        }
    }
};

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    priority_queue<int, vector<int>, compare> q;

    int n;
    cin>>n;

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