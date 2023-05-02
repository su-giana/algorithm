#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, vector<int> >& a, const pair<string, vector<int> >& b)
{
    if(a.second[0] != b.second[0])    return a.second[0] > b.second[0];
    if(a.second[1] != b.second[1])    return a.second[1] < b.second[1];
    if(a.second[2] != b.second[2])    return a.second[2] > b.second[2];
    return a.first < b.first;
}

int main()
{
    int n;
    cin>>n;

    vector<pair<string, vector<int> > > students;
    for(int i = 0 ; i<n ; i++)
    {
        string name;
        cin>>name;
        vector<int> scores;
        for(int j = 0 ; j<3 ; j++)
        {
            int score;
            cin>>score;
            scores.push_back(score);
        }
        students.push_back(make_pair(name, scores));
    }

    stable_sort(students.begin(), students.end(), compare);
    for(int i = 0 ; i<n ; i++)
    {
        cout<<students[i].first<<'\n';
    }
}