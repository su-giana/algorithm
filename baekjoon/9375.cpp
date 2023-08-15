#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> clothes;
unordered_map<string, int> map;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int index = 0;
        
        while(n--)
        {
            string item;
            cin>>item;

            string type;
            cin>>type;

            if(map.find(type) == map.end())
            {
                map.insert(make_pair(type, index));
                clothes.push_back(1);
                index++;
            }
            else
            {
                clothes[map[type]]++;
            }
        }

        int c_size = clothes.size();
        long long ans = 1;
        for(int i = 0 ; i<c_size ; i++)
        {
            ans *= (clothes[i] + 1);
        }

        cout<<ans-1<<'\n';
        map.clear();
        clothes.clear();
    }
}