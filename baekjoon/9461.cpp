#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    vector<pair<long long, long long> > waves(101, make_pair(0, 0));
    deque<long long> answers = {1, 1, 1, 2, 2};

    waves[1].first = 1; waves[1].second = 0;
    waves[2].first = 1; waves[2].second = 0;
    waves[3].first = 1; waves[3].second = 0;
    waves[4].first = 1; waves[4].second = 1;
    waves[5].first = 2; waves[5].second = 0;
    
    for(int i = 6 ; i<101 ; i++)
    {
        waves[i].first = answers.front();
        answers.pop_front();
        waves[i].second = waves[i-1].first + waves[i-1].second;
        answers.push_back(waves[i].first + waves[i].second);
    }

    int t;
    cin>>t;
    for(int k = 0 ; k<t ; k++)
    {
        int n;
        cin>>n;
        cout<<waves[n].first + waves[n].second<<endl;
    }

    return 0;
}