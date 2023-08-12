#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<long long> > map(20, vector<long long>(20, 0));
long long n;

void slide(long long type)
{
    switch(type)
    {
        // up
        case 0:
        {
            for(long long i = 0 ; i<n ; i++)
            {
                deque<long long> solved;
                deque<long long> nums;
                for(long long j = 0 ; j<n ; j++)
                {
                    if(map[j][i] != 0)
                    {
                        if(!nums.empty() && nums.back() == map[j][i])
                        {
                            nums.pop_back();
                            while(!nums.empty())
                            {
                                solved.push_back(nums.front());
                                nums.pop_front();
                            }
                            solved.push_back(2*map[j][i]);
                        }
                        else
                        {
                            nums.push_back(map[j][i]);
                        }
                    }
                }
                for(long long j = 0 ; j<n ; j++)
                {
                    if(!solved.empty())
                    {
                        map[j][i] = solved.front();
                        solved.pop_front();
                    }
                    else if(!nums.empty())
                    {
                        map[j][i] = nums.front();
                        nums.pop_front();
                    }
                    else
                    {
                        map[j][i] = 0;
                    }
                }
            }
            break;
        }
        // down
        case 1:
        {
            for(long long i = 0 ; i<n ; i++)
            {
                deque<long long> solved;
                deque<long long> nums;
                for(long long j = n-1 ; j>=0 ; j--)
                {
                    if(map[j][i] != 0)
                    {
                        if(!nums.empty() && nums.back() == map[j][i])
                        {
                            nums.pop_back();
                            while(!nums.empty())
                            {
                                solved.push_back(nums.front());
                                nums.pop_front();
                            }
                            solved.push_back(2*map[j][i]);
                        }
                        else
                        {
                            nums.push_back(map[j][i]);
                        }
                    }
                }
                for(long long j = n-1 ; j>=0 ; j--)
                {
                    if(!solved.empty())
                    {
                        map[j][i] = solved.front();
                        solved.pop_front();
                    }
                    else if(!nums.empty())
                    {
                        map[j][i] = nums.front();
                        nums.pop_front();
                    }
                    else
                    {
                        map[j][i] = 0;
                    }
                }
            }
            break;
        }
        // left
        case 2:
        {
            for(long long i = 0 ; i<n ; i++)
            {
                deque<long long> solved;
                deque<long long> nums;
                for(long long j = 0 ; j<n ; j++)
                {
                    if(map[i][j] != 0)
                    {
                        if(!nums.empty() && nums.back() == map[i][j])
                        {
                            nums.pop_back();
                            while(!nums.empty())
                            {
                                solved.push_back(nums.front());
                                nums.pop_front();
                            }
                            solved.push_back(2*map[i][j]);
                        }
                        else
                        {
                            nums.push_back(map[i][j]);
                        }
                    }
                }
                for(long long j = 0 ; j<n ; j++)
                {
                    if(!solved.empty())
                    {
                        map[i][j] = solved.front();
                        solved.pop_front();
                    }
                    else if(!nums.empty())
                    {
                        map[i][j] = nums.front();
                        nums.pop_front();
                    }
                    else
                    {
                        map[i][j] = 0;
                    }
                }
            }
            break;
        }
        // right
        case 3:
        {
            for(long long i = 0 ; i<n ; i++)
            {
                deque<long long> solved;
                deque<long long> nums;
                for(long long j = n-1 ; j>=0 ; j--)
                {
                    if(map[i][j] != 0)
                    {
                        if(!nums.empty() && nums.back() == map[i][j])
                        {
                            nums.pop_back();
                            while(!nums.empty())
                            {
                                solved.push_back(nums.front());
                                nums.pop_front();
                            }
                            solved.push_back(2*map[i][j]);
                        }
                        else
                        {
                            nums.push_back(map[i][j]);
                        }
                    }
                }
                for(long long j = n-1 ; j>=0 ; j--)
                {
                    if(!solved.empty())
                    {
                        map[i][j] = solved.front();
                        solved.pop_front();
                    }
                    else if(!nums.empty())
                    {
                        map[i][j] = nums.front();
                        nums.pop_front();
                    }
                    else
                    {
                        map[i][j] = 0;
                    }
                }
            }
            break;
        }
    }
}

long long dfs(long long cnt)
{
    if(cnt == 0)
    {
        long long maxi = 0;
        for(long long i = 0 ; i<n ; i++)
        {
            maxi = max(maxi, *max_element(map[i].begin(), map[i].end()));
        }
        return maxi;
    }


    long long ans = 0;
    for(long long i = 0 ; i<4 ; i++)
    {
        vector<vector<long long> > cp = map;
        slide(i);
        ans = max(ans, dfs(cnt-1));
        map = cp;
    }

    return ans;
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

    cin>>n;
    for(long long i = 0 ; i<n ; i++)
    {
        for(long long j = 0 ; j<n ; j++)
        {
            long long val;
            cin>>val;
            map[i][j] = val;
        }
    }

    cout<<dfs(5);
}