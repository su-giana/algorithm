#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long a, b;

unordered_map<long long, long long> cache;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long cntOnes(long long num)
{
    if(num == 0)    return 0;
    if(num == 1)    return 1;

    if(cache.find(num) != cache.end())  return cache[num];

    long long prevSq = 1;

    while(prevSq<=num)   prevSq *= 2;
    prevSq /= 2;
    prevSq -= 1;

    return cache[num] = cntOnes(prevSq) + cntOnes(num - prevSq - 1) + (num - prevSq);
}

int main()
{
    init();

    cin>>a>>b;

    cout<<cntOnes(b) - cntOnes(a-1);
}

