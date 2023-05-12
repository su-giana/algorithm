#include <iostream>
#include <vector>

using namespace std;

vector<int> q;

void queue(int x)
{
    q.push_back(x);
}

void queue(string cmd)
{
    if(cmd=="pop")
    {
        if(q.empty())
        {
            cout<<-1<<endl;
            return;
        }
        cout<<q.front()<<endl;
        q.erase(q.begin());
    }
    else if(cmd=="size")
    {
        cout<<q.size()<<endl;
    }
    else if(cmd=="empty")
    {
        int ans = q.empty() ? 1 : 0;
        cout<< ans;
        cout<<endl;
    }
    else if(cmd=="front")
    {
        int ans = q.empty() ? -1 : q.front();
        cout<<ans;
        cout<<endl;
    }
    else if(cmd=="back")
    {
        int ans = q.empty() ? -1 : q.back();
        cout<<ans;
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        string cmd;
        cin>>cmd;

        if(cmd=="push")
        {
            int num;
            cin>>num;
            queue(num);
        }
        else
        {
            queue(cmd);
        }
    }
}