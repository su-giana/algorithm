#include <vector>
#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;

    vector<int> aCards;
    vector<int> bCards;

    for(int i = 0 ; i<a ; i++)
    {
        int card;
        cin>>card;
        aCards.push_back(card);
    }
    for(int i = 0 ; i<b ; i++)
    {
        int card;
        cin>>card;
        bCards.push_back(card);
    }

    int ans = 0;

    for(int i = 0 ; i<b ; i++)
    {
        deque<int> temp;
        int tempAns = 0;
        for(int j = i ; j<b ; j++)   
            temp.push_back(bCards[j]);
        
        for(int j = 0 ; j<a && !temp.empty() ; j++)
        {
            if(temp.front() == aCards[j])
            {
                tempAns++;
                temp.pop_front();
            }
        }

        ans = max(tempAns, ans);
    }
        
    cout<<ans;
}