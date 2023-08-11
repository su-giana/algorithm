#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<long long> nums;

long long dfs()
{
    
}

vector<string> split(string s, char deli)
{
    stringstream ss(s);
    string temp;
    vector<string> answer;

    while(getline(ss, temp, deli))
    {
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    init();

    string s;

    cin>>s;

    vector<string> minus = split(s, '-');
    int m_size = minus.size();

    for(int i = 0 ; i<m_size ; i++)
    {
        if(i == 0)
        {
            vector<string> plus = split(minus[i], '+');
            int p_size = plus.size();
            for(int j = 0 ; j<p_size ; j++)
            {
                nums.push_back(stoll(plus[j]));
            }
        }
        else
        {
            vector<string> plus = split(minus[i], '+');
            int p_size = plus.size();
            nums.push_back(stoll(plus[0]));
            for(int j = 1 ; j<p_size ; j++)
            {
                nums.push_back(stoll(plus[j]));
            }
        }
    }

    cout<<dfs();
}