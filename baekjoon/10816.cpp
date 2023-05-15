#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearchRight(vector<int>& cards, int card)
{
    int n = cards.size();

    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int mid = left + (right - left) / 2;

        if(cards[mid] <= card)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return left-1;
}

int binSearchLeft(vector<int>& cards, int card)
{
    int n = cards.size();

    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int mid = left + (right - left) / 2;

        if(cards[mid] >= card)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return right+1;
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

        int ans = 0;
        int left = binSearchLeft(cards, card);
        int right = binSearchRight(cards, card);

        cout<<right - left + 1<<" ";
    }
}