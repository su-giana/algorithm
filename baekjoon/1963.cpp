#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int chDigit(string a, string b, vector<int> primes)
{
    queue<string> que;
    que.push(a);
    primes[stoi(a)] = 0;

    while(!que.empty())
    {
        string cur = que.front();
        que.pop();
        if(primes[stoi(cur)] >= primes[stoi(b)])    continue;

        for(int i = 0 ; i<4 ; i++)
        {
            for(char j = '0' ; j<='9' ; j++)
            {
                if(i==0 && j=='0')  continue;
                string next = cur;
                next[i] = j;
            
                if(primes[stoi(next)] > primes[stoi(cur)] + 1)
                {
                    primes[stoi(next)] = primes[stoi(cur)] + 1;
                    que.push(next);
                }
            }
        }
    }

    return primes[stoi(b)];
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    vector<int> primes(10000, 10001);
    primes[0] = -1;
    primes[1] = -1;
    for(int i = 0 ; i*i<10000 ; i++)
    {
        if(primes[i]==-1)  continue;

        for(int j = i*i ; j<10000 ; j+=i)
        {
            primes[j] = -1;
        }
    }

    init();

    int t;
    cin>>t;

    while(t--)
    {
        string start, end;
        cin>>start>>end;

        int minCnt = chDigit(start, end, primes);
        
        if(minCnt==10001)            cout<<"Impossible"<<'\n';
        else                         cout<<minCnt<<'\n';
    }
}