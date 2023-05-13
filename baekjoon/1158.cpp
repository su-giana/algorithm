#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;

    deque<int> q;
    for(int i = 1 ; i<=n ; i++)
    {
        q.push_back(i);
    }

    cout<<"<";
    while(q.size()>1)
    {
        int K = q.size() < k ? k % q.size() : k;
        for(int i = 1 ; i < K ; i++)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        cout<<q.front()<<", ";
        q.pop_front();
    }
    cout<<q.front()<<">";
}