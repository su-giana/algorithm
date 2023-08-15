#include <iostream>
#include <vector>

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

    int n, m;
    cin>>n>>m;

    string s;
    cin>>s;
    vector<int> pos;

    bool startI = true;
    int len = 0;
    int ans = 0;
    for(int i = 0 ; i<m ; i++)
    {
        if(startI && s[i] == 'I')
        {
            len++;
            startI = false;
        }
        else if(!startI && s[i] == 'O')
        {
            len++;
            startI = true;
        }
        else
        {
            if(len!=0 && len!=1)
            {
                pos.push_back(len%2==0 ? len-1 : len);
            }
            if(s[i] == 'I')
            {
                len = 1;
                startI = false;
            }
            else
            {
                len = 0;
                startI = true;
            }
        }
    }
    if(len!=0 && len!=1)
    {
        pos.push_back(len%2==0 ? len-1 : len);
    }

    int p_size = pos.size();
    for(int i = 0 ; i<p_size ; i++)
    {
        ans += pos[i] - 2*n+1 < 0 ? 0 : (pos[i] - (2*n+1)) /2 + 1;
    }

    cout<<ans;
}