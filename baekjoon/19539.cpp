#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> trees;
    for(int i = 0 ; i<n ; i++)
    {
        int a;
        cin>>a;

        trees.push_back(a);
    }

    sort(trees.begin(), trees.end());
    priority_queue<int, vector<int>, greater<int> > remains;
    for(int i = 0 ; i<n ; i++)
    {
        int tree = trees[i];
        while(!remains.empty() && tree >= remains.top())
        {
            tree -= remains.top();
            remains.pop();
        }

        int remain = (3 - tree%3);
        if(!remain || !(tree%3))    continue;
        remains.push(remain);
    }

    if(remains.empty())     cout<<"YES";
    else                    cout<<"NO";
}