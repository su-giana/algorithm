#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}

int t;

int main()
{
    init();

    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int answer = 0;

        int score = 0;
        int s_size = s.size();
        for(int i = 0 ; i<s_size ; i++)
        {
            if(s[i] == 'O')
            {
                score++;
                answer += score;
            }
            else
            {
                score = 0;
            }
        }

        cout<<answer<<'\n';
    }
}