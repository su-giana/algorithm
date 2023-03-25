#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

void print_v(vector<int>& arrs)
{
    for(int i=0;i<arrs.size();i++)
    {
        cout<<arrs[i]<< " ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int> > f;
    vector<int> m;
    int m_min;
    priority_queue<int, vector<int>, greater<int> > e;

    for(int i=1;i<=3;i++)
    {
        int num;
        cin>>num;
        f.push(num);
    }
    e.push(f.top());
    f.pop();
    m.push_back(f.top());
    make_heap(m.begin(), m.end());
    f.pop();
    m_min = m[0];
    
    for(int i=4 ; i<=n ; i++)
    {
        int num;
        cin>>num;
        int t = ((double) i-2)/3;

        if(num<=m_min)
        {
            f.push(num);
        }
        else if(num<m[0])
        {
            m.push_back(num);
            push_heap(m.begin(), m.end());
        }
        else
        {
            e.push(num);
        }

        if((i-2)%3==0)
        {
            while(f.size()>t+1)
            {
                m_min = f.top();
                m.push_back(f.top());
                push_heap(m.begin(), m.end());
                f.pop();
            }
            while(e.size()>t)
            {
                m.push_back(e.top());
                push_heap(m.begin(), m.end());
                e.pop();
            }
            while(m.size()>t+1 && e.size()<t)
            {
                e.push(m[0]);
                pop_heap(m.begin(), m.end());
                m.pop_back();
            }
            if(m.size()>t+1 && f.size()<t+1)
            {
                make_heap(m.begin(), m.end(), greater<int>());
                while(m.size() > t+1 && f.size()<t+1)
                {
                    f.push(m[0]);
                    pop_heap(m.begin(), m.end());
                    m.pop_back();
                }
                make_heap(m.begin(), m.end());
            }

            cout<<"m : ";
            print_v(m);
            cout<<f.top()<<" "<<m[0]<<endl;
        }
    }
}
