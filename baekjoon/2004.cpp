#include <iostream>
#include <vector>

using namespace std;

pair<long long, long long> getDivs(long long n)
{
    pair<long long, long long> cnt;
    int two = 0, five = 0;
    
    for(long long i = 2 ; i<=n ; i *= 2)
    {
        cnt.first += n / i;
    }
    for(long long i = 5 ; i<=n ; i *= 5)
    {
        cnt.second += n / i;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, m;
    cin>>n>>m;

    pair<long long, long long> c_n = getDivs(n);
    pair<long long, long long> c_nm = getDivs(n - m);
    pair<long long, long long> c_m = getDivs(m);

    long long twos = c_n.first - (c_nm.first + c_m.first);
    long long fives = c_n.second - (c_nm.second + c_m.second);

    int ans = twos>fives ? fives : twos;

    cout<<ans;
}