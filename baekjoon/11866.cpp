#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    cin>>n>>k;

    queue<int> q;
    for(int i = 1 ; i<=n ; i++)
        q.push(i);

    cout<<"<";
    while(q.size()>1)
    {
        for(int i = 0 ; i<k-1 ; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<", ";
        q.pop();
    }
    cout<<q.front()<<">";
}