#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> sugars(n+5, -1);
    sugars[4] = 0;

    for(int i = 5 ; i<sugars.size() ; i++)
    {
        int three = -1;
        int five = -1;
        if(sugars[i - 3] != -1)
        {
            three = sugars[i - 3] + 1;
        }
        if(sugars[i - 5] != -1)
        {
            five = sugars[i - 5] + 1;
        }
        if(three != -1 && five != -1)   sugars[i] = min(three, five);
        else if(three != -1)    sugars[i] = three;
        else if(five != -1)     sugars[i] = five;
    }

    cout<<sugars[n+4];
    return 0;
}