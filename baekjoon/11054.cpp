#include <iostream>
#include <vector>
#include <algorithm>

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

    int A;
    cin>>A;

    vector<int> nums(A, 0);
    for(int i = 0 ; i<A ; i++)
    {
        int num;
        cin>>num;
        nums[i] = num;
    }

    vector<int> dpPos(A, 1);
    vector<int> dpNeg(A, 1);

    for(int i = 0 ; i<A ; i++)
    {
        int temp = nums[i];
        for(int j = 0 ; j<i ; j++)
        {
            if(temp>nums[j])
            {
                dpPos[i] = max(dpPos[i], dpPos[j] + 1);
            }
        }
    }

    for(int i = A-1 ; i>=0 ; i--)
    {
        int temp = nums[i];
        for(int j = i+1 ; j<A ; j++)
        {
            if(temp>nums[j])
            {
                dpNeg[i] = max(dpNeg[i], dpNeg[j] + 1);
            }
        }
    }

    for(int i = 0 ; i<A ; i++)
        dpPos[i] = max({dpPos[i], dpNeg[i], dpPos[i] + dpNeg[i] - 1});

    cout<<*max_element(dpPos.begin(), dpPos.end());
}