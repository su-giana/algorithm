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
    int n, m, k;
    cin>>n>>m>>k;

    int maxTeam = (n/2) > m ? m : n/2;
    int remain = (n - maxTeam*2) + (m - maxTeam);
    k = k-remain<0 ? 0 : k-remain;

    maxTeam -= (k/3);
    if(k%3 ==0) { cout<<maxTeam;    return 0; }
    else        { cout<<maxTeam-1;  return 0; }
}