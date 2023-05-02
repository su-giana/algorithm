#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void st(int num)
{
    nums.push_back(num);
}

void st(string com)
{
    if(com == "pop")
    {
        if(nums.empty())    { cout<<"-1"<<'\n'; return; }
        cout<<nums.back()<<'\n';
        nums.pop_back();
        return;
    }
    if(com == "top")
    {
        if(nums.empty())    {cout<<"-1"<<'\n'; return;}
        cout<<nums.back()<<'\n';
        return;
    }
    if(com == "size")
    {
        cout<<nums.size()<<'\n';
        return;
    }
    if(com == "empty")
    {
        if(nums.empty())    cout<<1<<'\n';
        else                cout<<0<<'\n';
        return;
    }
}

int main()
{
    int n;
    cin>>n;
    
    for(int i = 0 ; i<n ; i++)
    {
        string com;
        cin>>com;
        if(com == "push")
        {
            int num;
            cin>>num;
            st(num);
        }
        else
        {
            st(com);
        }
    }
}