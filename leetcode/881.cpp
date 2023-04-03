#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        
        int answer = 0;
        int left = 0, right = people.size()-1;

        while(left<=right)
        {

          if(people[left] + people[right] <= limit)
          {
            answer++;
            right--;
            left++;
          }
          else
          {
            answer++;
            right--;
          }
        }
        return answer;
    }
};