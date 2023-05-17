#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int getUseNumPad(string& n, string s, vector<bool>& buttons)
{
    string cmp;

    if(s.length() != 0) 
    {
        cmp = to_string(stoi(s));
    }
    if(s.length() == n.length()+1)
    {
        return abs(stoi(n) - stoi(cmp)) + cmp.length();
    }

    int now = s.length() == 0 ? abs(stoi(n) - 100) : abs(stoi(n) - stoi(cmp)) + cmp.length();

    int minCnt = INT_MAX;
    for(int i = 0 ; i<10 ; i++)
    {
        if(buttons[i])
        {
            string temp = s + (char) (i + '0');
            minCnt = min(minCnt, getUseNumPad(n, temp, buttons));
        }
    }
    
    return min(minCnt, now);
}

int main()
{
    init();

    string n;
    cin>>n;

    int m;
    cin>>m;
    vector<bool> buttons(10, true);
    for(int i = 0 ; i<m ; i++)
    {
        int button;
        cin>>button;
        buttons[button] = false;
    }

    cout<<getUseNumPad(n, "", buttons);
}