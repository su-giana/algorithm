#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> cnt(8001, 0);

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    int n;
    cin>>n;

    while(n--)
    {
        int num;
        cin>>num;
        cnt[num + 4000]++;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    
    double avg = accumulate(nums.begin(), nums.end(), 0);
    avg /= nums.size();
    avg = round(avg);
    cout<< (int) avg<<'\n';

    int mid = nums.size()/2;
    cout<<nums[mid]<<'\n';

    int commonest = 0;
    bool isPassed = false;
    for(int i = 1 ; i<8001 ; i++)
    {
        if(cnt[commonest] < cnt[i])
        {
            commonest = i;
            isPassed = false;
        }
        else if(cnt[commonest] == cnt[i] && !isPassed)
        {
            commonest = i;
            isPassed = true;
        }
    }
    cout<<commonest - 4000<<'\n';

    cout<<nums[nums.size()-1] - nums[0];
}