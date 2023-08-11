#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long> > fibonacci(41, make_pair(0, 0));

void initialize()
{
    fibonacci[0].first = 1;
    fibonacci[1].second = 1;

    for(int i = 2 ; i<=40 ; i++)
    {
        fibonacci[i].first = fibonacci[i-1].first + fibonacci[i-2].first;
        fibonacci[i].second = fibonacci[i-1].second + fibonacci[i-2].second;
    }
}

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    initialize();

    int n;
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        cout<<fibonacci[num].first<<" "<<fibonacci[num].second<<'\n';
    }
}