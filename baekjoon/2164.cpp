#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

deque<int> nums;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    cin>>n;
    int cnt = 1;

    for(int i = 1 ; i<=n ; i++)
    {
        nums.push_back(i);
    }

    while(nums.size() > 1)
    {
        if(cnt%2 == 1)
        {
            nums.pop_front();
        }
        else
        {
            nums.push_back(nums.front());
            nums.pop_front();
        }
        cnt++;
    }

    cout<<nums.front();
}