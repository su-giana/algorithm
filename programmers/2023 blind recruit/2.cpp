#include <string>
#include <vector>
#include <iostream>

using namespace std;

void deleteZeros(vector<int>& del)
{
    while(!del.empty())
    {
        if(del.back() == 0)
            del.pop_back();
        else
            break;
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(!deliveries.empty() || !pickups.empty())
    {
        deleteZeros(deliveries);
        deleteZeros(pickups);
        
        answer += max(deliveries.size(), pickups.size());
        
        int temp = cap;
        while(!deliveries.empty() && temp>0)
        {
            if(deliveries.back() == 0)  deliveries.pop_back();
            else if(deliveries.back() > temp)
            {
                int cur = deliveries.back();
                deliveries.pop_back();
                deliveries.push_back(cur - temp);
                break;                                                                                                                                                   
            }
            else
            {
                temp -= deliveries.back();
                deliveries.pop_back();
            }
        }
        
        temp = cap;
        while(!pickups.empty() && temp>0)
        {
            if(pickups.back() == 0)  pickups.pop_back();
            else if(pickups.back() > temp)
            {
                int cur = pickups.back();
                pickups.pop_back();
                pickups.push_back(cur - temp);
                break;
            }
            else
            {
                temp -= pickups.back();
                pickups.pop_back();
            }
        }
    }
    
    return answer*2;
}