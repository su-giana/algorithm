#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

void fillBottles(string cur, vector<int>& bottles)
{
    int fZero = cur.find(' ');
    int sZero = cur.find(' ', fZero+1);
    
    bottles[0] = stoi(cur.substr(0, fZero));
    bottles[1] = stoi(cur.substr(fZero+1, sZero - fZero - 1));
    bottles[2] = stoi(cur.substr(sZero+1));
}

void getAllCase(int a, int b, int c, set<int>& fullA)
{
    vector<int> maxVol = {a, b, c};
    deque<string> q;
    unordered_map<string, int> cases;
    string cur = "0 0 " + to_string(c);
    q.push_back(cur);
    cases.insert(make_pair(cur, 1));

    while(!q.empty())
    {
        cur = q.front();
        q.pop_front();

        vector<int> bottles(3, 0);
        fillBottles(cur, bottles);

        if(bottles[0] == 0)
        {
            fullA.insert(bottles[2]);
        }

        for(int i = 0 ; i<3 ; i++)
        {
            if(bottles[i] == maxVol[i]) continue;
            for(int j = 0 ; j<3 ; j++)
            {
                vector<int> cBottles(bottles.begin(), bottles.end());   
                if(i==j)    continue;
                if(bottles[j] == 0) continue;

                cBottles[i] = bottles[j] + bottles[i] > maxVol[i] ? maxVol[i] : bottles[i] + bottles[j];
                cBottles[j] = bottles[j] < (maxVol[i] - bottles[i]) ? 0 : (bottles[j] - (maxVol[i] - bottles[i]));
                string next = to_string(cBottles[0]) + " " + to_string(cBottles[1]) + " " + to_string(cBottles[2]);
                if(cases.count(next) == 0)
                {
                    q.push_back(next);
                    cases.insert(make_pair(next, 1));
                }
            }
        }
    }
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int a, b, c;
    cin>>a>>b>>c;
    set<int> fullA;

    getAllCase(a, b, c, fullA);

    vector<int> cases(fullA.begin(), fullA.end());
    sort(cases.begin(), cases.end());
    int n = cases.size();
    for(int i = 0 ; i<n ; i++)
    {
        cout<<cases[i];
        if(i!=n-1)
            cout<<" ";
    }
}