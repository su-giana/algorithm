#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, m, b;
    cin>>n>>m>>b;

    long long ans = LLONG_MAX;
    long long max_height = 0;

    vector<vector<int> > map(n, vector<int>(m, 0));

    int min_n = 257;
    int max_n = 0;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int num;
            cin>>num;

            min_n = min(min_n, num);
            max_n = max(max_n, num);
            map[i][j] = num;
        }
    }

    for(int k = min_n ; k<=max_n ; k++)
    {
        long long less = 0;
        long long more = 0;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(map[i][j] > k)
                {
                    more += map[i][j] - k;
                }
                else if(map[i][j] < k)
                {
                    less += k - map[i][j];
                }
            }
        }

        if(b + more < less) continue;
        long long time = less + more*2;
        if(ans >= time)
        {
            ans = time;
            max_height = k;
        }
    }

    cout<<ans<<" "<<max_height;
}