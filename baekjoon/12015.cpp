#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums(1000000, 0);

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

    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    
}