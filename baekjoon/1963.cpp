#include <iostream>
#include <vector>

using namespace std;

int chDigit(string a, string b, vector<int>& primes, int cnt)
{
    if(a==b)    return cnt;
    cout<<a<<endl;
    if(stoi(a)<1000)    return 10000;   

    int isPrime = 10000;
    string temp = "";

    for(int i = 0 ; i<4 ; i++)
    {
        for(char j = '0' ; j<='9' ; j++)
        {
            if(temp[i]==j)    continue;
            temp = a;
            temp[i] = j;
            
            if(primes[stoi(temp)])
            {
                isPrime = min(isPrime, chDigit(temp, b, primes, cnt+1));
            }
        }
    }

    if(isPrime==10000)    return 10000;
    return isPrime;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    vector<int> primes(10000, 0);
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

        int cnt = chDigit(start, end, primes, 0);
        
        if(cnt==10000) cout<<"Impossible"<<'\n';
        else        cout<<cnt<<'\n';
    }
}