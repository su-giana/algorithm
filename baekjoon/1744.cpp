#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bindPos(deque<int>& q, vector<int>& stored)
{
    while(!q.empty())
    {
        int left = q.back();
        q.pop_back();
        if(q.empty())
        {
            q.push_back(left);
            break;
        }

        int right = q.back();
        q.pop_back();

        if(left<=0 || right<=0)
        {
            q.push_back(right);
            q.push_back(left);
            break;
        }
        else
        {
            if(left*right > left+right) stored.push_back(left * right);
            else
            {
                stored.push_back(left);
                stored.push_back(right);
            }
        }
    }
}

void bindNeg(deque<int>& q, vector<int>& stored)
{
    while(!q.empty())
    {
        int left = q.front();
        q.pop_front();
        if(q.empty())
        {
            q.push_front(left);
            break;
        }

        int right = q.front();
        q.pop_front();

        if(left>0 || right>0)
        {
            q.push_front(right);
            q.push_front(left);
            break;
        }
        else if(left<0 && right<0 )
        {
            stored.push_back(left*right);
        }
        else if(left == 0 || right == 0)
        {
            stored.push_back(0);
        }
    }
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<int> nums(n, 0);
    for(int i = 0 ; i < n ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());

    deque<int> q(nums.begin(), nums.end());
    vector<int> duplicated;

    bindNeg(q, duplicated);
    bindPos(q, duplicated);

    int ans = 0;
    while(!q.empty())
    {
        ans += q.front();
        q.pop_front();
    }

    cout<<ans + accumulate(duplicated.begin(), duplicated.end(), 0);
}