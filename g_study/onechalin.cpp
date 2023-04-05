#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> potions(n, 0);

    for(int i = 0 ; i<n ; i++)
    {
        int potion;
        cin>>potion;
        potions[i] = potion;
    }

    sort(potions.begin(), potions.end());

    int left = 0, right = 1;

    int temp = abs(potions[0] + potions[1]);
    for(int i = 2 ; i<n ; i++)
    {
        if(temp>=abs(potions[i] + potions[0]))
        {
            temp = abs(potions[i] + potions[0]);
            right++;
        }
        else    break;
    }

    int ans = temp;
    int pos1 = left, pos2 = right;
    left++;
    while(left < right)
    {
        temp = abs(potions[left] + potions[right]);
        while(left+1<right)
        {
            if(temp > abs(potions[left] + potions[right-1]))
            {
                right--;
                temp = abs(potions[left] + potions[right]);
            }
            else    break;
        }
        if(temp<ans)
        {
            ans = temp;
            pos1 = left;
            pos2 = right;
        }
        left++;
    }

    cout<<min(potions[pos1], potions[pos2])<<" "<<max(potions[pos1], potions[pos2]);
}