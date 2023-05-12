#include <iostream>
#include <vector>

using namespace std;

vector<int> q;

void queue(string cmd, int x)
{
    if(cmd=="push_back")    q.push_back(x);
    else                    q.insert(q.begin(), x);
}

void queue(string cmd)
{
    if(cmd=="pop_front")
    {
        if(q.empty())
        {
            cout<<-1<<endl;
            return;
        }
        cout<<q.front()<<endl;
        q.erase(q.begin());
    }
    else if(cmd=="pop_back")
    {
        if(q.empty())
        {
            cout<<-1<<endl;
            return;
        }
        cout<<q.back()<<endl;
        q.pop_back();
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

        if(cmd=="push_front" || cmd=="push_back")
        {
            int num;
            cin>>num;
            queue(cmd, num);
        }
        else
        {
            queue(cmd);
        }
    }
}