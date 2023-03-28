#include <iostream>
#include <vector>

using namespace std;

// Time limit over
/*class Solution 
{
public:
    int calTickets(vector<int>& days, vector<int>& costs, int cost)
    {
        cout<<cost<<endl;
        if(days.size()==0)  return cost;

        vector<int> tickets = {1, 7, 30};

        vector<int> prices(3, 0);

        for(int i=0 ; i<3 ; i++)
        {
            bool in = false;

            for(int j = 0; j<days.size() ; j++)
            {
                if(days[j] >= days[0] + tickets[i])
                {
                    in = true;
                    vector<int> temp;
                    temp.assign(days.begin()+j, days.end());
                    prices[i] = calTickets(temp, costs, cost + costs[i]);
                    break;
                }
            }

            if(!in)
            {
                prices[i] = cost + costs[i];
            }
        }

        return *min_element(prices.begin(), prices.end());
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        return calTickets(days, costs, 0);
    }
}; */

class Solution 
{
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<pair<int, int> > prices(396, make_pair(0, 0));

        for(int i=0 ; i<days.size() ; i++)
        {
            prices[days[i]+30].first = 1;
        }

        for(int i=31 ; i<prices.size() ; i++)
        {
            if(prices[i].first == 1)
            {
                prices[i].second = 
                min({prices[i - 1].second + costs[0], prices[i - 7].second + costs[1], prices[i - 30].second + costs[2]});
            }
            else
            {
                prices[i].second = prices[i-1].second;
            }
        }

        return prices[prices.size() - 1].second;
    }
};