#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin>>n>>a>>b;

    if(n==1)
    {
        if(a==b)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        cout<<a<<":"<<b<<endl;
        return 0;
    }

    int draw = 0;
    vector<pair<int, int> > scores;
    scores.push_back(make_pair(a, b));
    if(scores.back().first == 0 && scores.back().second == 0) draw++;

    for(int i = 1 ; i<n ; i++)
    {
        pair<int, int> pre = scores.back();
        if(pre.first + pre.second <= 1) 
        {
            scores.push_back(make_pair(0, 0));
            draw++;
        }
        else
        {
            scores.pop_back();

            if((pre.first>pre.second && pre.second>0) || (pre.first<=pre.second && pre.first<=0))
            {
                scores.push_back(make_pair(0, 1));
                scores.push_back(make_pair(pre.first, pre.second-1));
            }
            else if((pre.first<=pre.second && pre.first>0) || (pre.first>pre.second && pre.second<=0))
            {
                scores.push_back(make_pair(1, 0));
                scores.push_back(make_pair(pre.first-1, pre.second));
            }
        }
    }
    

    cout<<draw<<endl;
    for(int i = 0 ; i<scores.size() ; i++)
    {
        cout<<scores[i].first<<":"<<scores[i].second<<endl;
    }
}