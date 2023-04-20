#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <numeric>

using namespace std;

unordered_map<string, int> paths;

string getString(vector<int>& trees)
{
    string ans = "";
    for(int i = 0 ; i<trees.size() ; i++)
        ans += trees[i];
    return ans;
}

int getMax(const vector<int>& trees)
{
    int ones = 0, twos = 0;
    int n = trees.size();
    for(int i = 0 ; i<n ; i+=2)
    {
        ones += trees[i];
    }
    for(int i = 1 ; i<n ; i+=2)
    {
        twos += trees[i];
    }
    return ones>twos ? ones : twos;
}

vector<int> mergeTrees(vector<int>& trees, int depth)
{
    int n = trees.size();
    if(n==1 || !depth)
    {
        return trees;
    }   

    vector<int> maxTree = trees;
    int maxValue = getMax(trees);
    string symbol = getString(maxTree);
    paths.insert(make_pair(symbol, maxValue));
    for(int i = 0 ; i<n-1 ; i++)
    {
        vector<int> temp;
        int tempValue = 0;

        for(int j = 0 ; j<i ; j++)
            temp.push_back(trees[j]);
        
        temp.push_back(trees[i] + trees[i+1]);

        for(int j = i+2 ; j<n ; j++)
            temp.push_back(trees[j]);

        symbol = getString(temp);
        if(paths.count(symbol))
        {
            tempValue = paths[symbol];
        }
        else
        {
            temp = mergeTrees(temp, depth-1);
            symbol = getString(temp);
            tempValue = getMax(temp);
            paths.insert(make_pair(symbol, tempValue));
        }
            
        if(tempValue > maxValue)
        {
            maxValue = tempValue;
            maxTree = temp;
        }
    }
    return maxTree;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> trees;
    int t, pre, count = 1;
    cin>>pre;

    for(int i = 0 ; i<n-1 ; i++)
    {
        cin>>t;

        if(pre == t)    count++;
        else
        {
            pre = t;
            trees.push_back(count);
            count = 1;
        }
    }
    trees.push_back(count);

    n = trees.size();

    if(m >= n-1)    { cout<<accumulate(trees.begin(), trees.end(), 0); return 0; }

    cout<<getMax(mergeTrees(trees, m));
}