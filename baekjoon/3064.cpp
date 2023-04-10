#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        vector<vector<int> > graph(n, vector<int>(n, 0));

        for(int i = 0 ; i<n ; i++)
        {
            string s;
            cin>>s;
            for(int j = 0 ; j<s.length() ; j++)
            {
                if(s[j] == '#')
                    graph[i][j] = -1;
                else
                    graph[i][j] = (int) s[j];
            }
        }
    }
}