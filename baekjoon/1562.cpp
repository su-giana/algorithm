#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;

int n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
}

int main()
{
    cin>>n;

    vector<vector<long long> > visited(1024, vector<long long>(10, 0));
    for(int i = 0; i<10 ; i++)  visited[(1<<i)][i] = 1;

    for(int i = 1 ; i<n ; i++)
    {
        vector<vector<long long> > temp(1024, vector<long long>(10, 0));
        for(int j = 0 ; j<10 ; j++)
        {
            for(int k = 0 ; k<1024 ; k++)
            {
                if(k & (1<<j))
                {
                    if(j > 0)
                    {
                        temp[k | (1<<(j-1))][j-1] = (temp[k | (1<<(j-1))][j-1] + visited[k][j]) % 1000000000;
                    }
                    if(j+1<10)
                    {
                        temp[k | (1<<(j+1))][j+1] = (temp[k | (1<<(j+1))][j+1] + visited[k][j]) % 1000000000;
                    }
                }
            }
        }

        visited = temp;
    }

    

    long long ans = 0;
    for(int i = 1 ; i<10 ; i++)
    {
        ans = (ans + visited[1023][i]) % 1000000000;
    }

    cout<<ans;
}