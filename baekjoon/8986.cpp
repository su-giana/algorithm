#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<long long> objs;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long getDistance(int k)
{
    long long sum = 0;
    for(int i = 0 ; i<N ; i++)
    {
        sum += abs(1LL*i * k - objs[i]);
    }

    return sum;
}

void solution()
{
    long long begin = 0;
    long long end = objs[N-1];

    while(end - begin >= 3)
    {
        long long a = (begin*2 + end) / 3;
        long long b = (begin + 2*end) / 3;
        long long distanceA = getDistance(a);
        long long distanceB = getDistance(b);

        if(distanceA >= distanceB)
        {
            begin = a;
        }
        else
        {
            end = b;
        }
    }

    long long res = LLONG_MAX;
    for(int i = begin ; i<=end ; i++)
        res = min(res, getDistance(i));

    cout<<res;
}

int main()
{
    init();

    cin>>N;

    for(int i = 0 ; i<N ; i++)
    {
        long long obj;
        cin>>obj;
        objs.push_back(obj);
    }

    solution();
}