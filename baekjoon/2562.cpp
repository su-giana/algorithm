#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    n = 9;

    vector<int> nums(n);

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;

        nums[i] = num;
    }

    int min_num = 0;
    for(int i = 1 ; i<n ; i++)
    {
        if(nums[min_num]<nums[i])
        {
            min_num = i;
        }
    }

    cout<<nums[min_num]<<endl;
    cout<<min_num+1;
}