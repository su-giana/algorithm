#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

bool isValid(pair<int, int>& cur)
{
    int vow = 0;

    for(int i = 0 ; i<5 ; i++)
    {
        if(cur.first & (1 << (vowel[i] - 'a')))    vow++;
    }

    if(vow>0 && cur.second-vow>1)    return true;
    else                    return false;
}

string convertString(int n)
{
    string s = "";

    for(int i = 0 ; i<26 ; i++)
    {
        if(n & (1<<i))
        {
            s += ('a' + i);
        }
    }

    return s;
}

int bitCount(int curStr)
{
    if(curStr == 0) return 0;
    return curStr%2 + bitCount(curStr/2);
}

void printCyphers(set<int>& passwords, vector<string>& ans, vector<char>& cyphers, int curStr, int l)
{
    int n = cyphers.size();
    int curLen = bitCount(curStr);
    pair<int, int> cur = make_pair(curStr, curLen);
    if(curLen == l && isValid(cur))   { ans.push_back(convertString(curStr));    return;}

    for(int i = 0 ; i<n ; i++)
    {
        int next = (1 << (cyphers[i] - 'a'));
        if(cur.first & next)   continue;
        if(passwords.count(curStr | next) == 0)
        {
            passwords.insert(curStr | next);
            printCyphers(passwords, ans, cyphers, curStr | next, l);
        }
    }
}

int main()
{
    init();

    int l, c;
    cin>>l>>c;
    vector<char> cyphers(c);

    for(int i = 0 ; i<c ; i++)
    {
        char ch;
        cin>>ch;
        cyphers[i] = ch;
    }

    set<int> passwords;
    vector<string> cypher;

    int next = 0;
    for(int i = 0 ; i<c ; i++)
    {
        next = 1<<(cyphers[i] - 'a');
        passwords.insert(next);
        printCyphers(passwords, cypher, cyphers, next, l);
    }

    int n = cypher.size();

    sort(cypher.begin(), cypher.end());
    
    for(int i = 0 ; i<n ; i++)
    {
        cout<<cypher[i]<<'\n';
    }
}