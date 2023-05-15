#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binSearch(vector<int>& cards, int card)
{
    int n = cards.size();

    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int mid = left + (right - left) / 2;

        if(cards[mid] == card)
        {
            return true;
        }
        else if(cards[mid] > card)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return false;
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

    int n;
    cin>>n;
    vector<int> cards(n, 0);
    for(int i = 0 ; i<n ; i++)
    {
        int card;
        cin>>card;
        cards[i] = card;
    }
    sort(cards.begin(), cards.end());

    int m;
    cin>>m;
    for(int i = 0 ; i<m ; i++)
    {
        int card;
        cin>>card;
        cout<<binSearch(cards, card)<<" ";
    }
}