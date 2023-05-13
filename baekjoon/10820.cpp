#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;

    while(getline(cin, s))
    {

        int space = 0, UC = 0, LC = 0, num = 0;
        int n = s.length();

        for(int i = 0 ; i<n ; i++)
        {
            char c = s[i];
            if(c==' ')
            {
                space++;
            }
            else if(c>=48 && c<=57)
            {
                num++;
            }
            else if(c>=65 && c<=90)
            {
                UC++;
            }
            else
            {
                LC++;
            }
        }
        cout<<LC<<" "<<UC<<" "<<num<<" "<<space<<endl;
    }
    return 0;
}