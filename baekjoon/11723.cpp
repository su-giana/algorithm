#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int m;
    cin>>m;
    
    int answer = 0;

    while(m--)
    {
        string cmd;
        cin>>cmd;

        if(cmd == "add")
        {
            int val;
            cin>>val;

            if(!(answer & (1<<val)))
            {
                answer |= (1<<val);
            }
        }
        else if(cmd == "remove")
            {
                int val;
            cin>>val;
                if(answer & (1<<val))
            {
                answer &= ~(1<<val);
            }
            }
            else if(cmd == "check")
            {
                int val;
            cin>>val;
                if(answer & (1<<val))
                {
                    cout<<"1"<<'\n';
                }
                else
                {
                    cout<<"0"<<"\n";
                }
            }
            else if(cmd == "toggle")
            {
                int val;
            cin>>val;
                answer ^= (1<<val);
            }
            else if(cmd == "all")
            {
                answer = INT_MAX;
            }
            else
            {
                answer = 0;
            }
    }
}