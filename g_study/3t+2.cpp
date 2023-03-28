#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int> > f;
    priority_queue<int, vector<int> > m;
    priority_queue<int, vector<int>, greater<int> > e;

    
    for(int i=1 ; i<=n ; i++)
    {
        int num;
        cin>>num;
        int t = ((double) i-2)/3;

        f.push(num);

        if(i==2)
        {
            m.push(f.top());
            f.pop();
        }
        else if((i-2)%3==0 && t>0)
        {
            for(int i=0 ; i<2 ; i++)
            {
                m.push(f.top());
                f.pop();
            }
            e.push(m.top());
            m.pop();

            cout<<f.top()<<" "<<m.top()<<endl;
        }
    }
}
