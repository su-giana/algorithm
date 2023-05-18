#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getNextNum(int s, char oper)
{
    int next;

    switch(oper)
    {
        case 'D':
        {
            next = 2*s % 10000;
            break;
        }
        case 'S':
        {
            next = (s - 1 + 10000) % 10000;
            break;
        }
        case 'L':
        {
            next = s%1000 * 10 + s/1000;
            break;
        }
        case 'R':
        {
            next = s%10 * 1000 + s/10;
            break;
        }
    }
    return next;
}

string getMinCnt(int a, int b)
{
    vector<char> oper = {'D', 'S', 'L', 'R'};
    vector<string> history(10000, "");
    vector<int> cntCh(10000, 10000);
    deque<int> que;

    que.push_back(a);
    cntCh[a] = 0;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop_front();

        if(cur == b)    break;
        if(cntCh[cur] >= cntCh[b])    continue;

        for(int i = 0 ; i<4 ; i++)
        {
            int next = getNextNum(cur, oper[i]);

            if(cntCh[next] > cntCh[cur] + 1)
            {
                cntCh[next] = cntCh[cur] + 1;
                history[next] = history[cur] + oper[i];

                que.push_back(next);
            }
        }
    }

    return history[b];
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;

        cout<<getMinCnt(a, b)<<'\n';
    }
}