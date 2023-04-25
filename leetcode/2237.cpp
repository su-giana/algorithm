#include <vector>
#include <iostream>
#include <priority_queue>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int> > infiniteSet;
    set<int> verifying;

    SmallestInfiniteSet() {
        for(int i = 1 ; i<=1000 ; i++)
        {
            infiniteSet.push(i);
            verifying.insert(i);
        }
    }
    
    int popSmallest() 
    {
        if(!infiniteSet.empty() && !verifying.empty())
        {
            int smallest = infiniteSet.top();
            infiniteSet.pop();
            verifying.erase(verifying.find(smallest));
            return smallest;
        }

        return NULL;
    }
    
    void addBack(int num) 
    {
        if(verifying.find(num) != verifying.end())
        {
            return;
        }    
        else
        {
            verifying.insert(num);
            infiniteSet.push(num);
            return;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */