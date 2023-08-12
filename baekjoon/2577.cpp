#include <iostream>
#include <vector>

using namespace std;

int a, b, c;

vector<int> answer(10, 0);

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    cin>>a>>b>>c;

    long long num = a * b * c;

    while(num)
    {
        answer[num%10]++;
        num /= 10;
    }

    for(int i = 0 ; i<10 ; i++)
    {
        cout<<answer[i]<<'\n';
    }
}