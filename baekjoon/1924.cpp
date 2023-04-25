#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> cal = 
    {
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31}
    };

    int m ,d;
    cin>>m>>d;

    for(int i = 1 ; i<m ; i++)
    {
        d += cal[i];
    }

    d %= 7;

    switch(d)
    {
        case 0:
            cout<<"SUN";    break;
        case 1:
            cout<<"MON";    break;
        case 2:
            cout<<"TUE";    break;
        case 3:
            cout<<"WED";    break;
        case 4:
            cout<<"THU";    break;
        case 5:
            cout<<"FRI";    break;
        case 6:
            cout<<"SAT";    break;
    }
}