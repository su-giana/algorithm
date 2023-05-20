#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <set>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<int> split(string s, char delimiter)
{
    vector<int> ans;
    stringstream ss(s);
    string temp;

    while(getline(ss, temp, delimiter))
    {
        ans.push_back(stoi(temp));
    }

    return ans;
}

void dfs(vector<int>& lotto, vector<bool>& visited, int start)
{
    int n = lotto.size();
    if(accumulate(visited.begin(), visited.end(), 0) == 6)
    {
        for(int i = 0 ; i<n ; i++)
        {
            if(visited[i])  cout<<lotto[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = start ; i<n ; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(lotto, visited, i+1);
            visited[i] = false;
        }
    }
}

int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(!n)  break;

        vector<int> lotto(n, 0);
        for(int i = 0 ; i<n ; i++)
        {
            int num;
            cin>>num;
            lotto[i] = num;
        }

        vector<bool> visited(n, false);

        dfs(lotto, visited, 0);
        cout<<'\n';
    }
}