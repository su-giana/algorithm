#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<int> arr(m+1, 1);
    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2 ; i<=m ; i++)
    {
        if(arr[i] == 0)   continue;

        for(int j = 2*i ; j<=m ; j+=i)
        {
            arr[j] = 0;
        }
    }

    for(int i = n ; i<=m ; i++)
    {
        if(arr[i])  cout<<i<<'\n';
    }
}