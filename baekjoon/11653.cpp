#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    int n;
    cin>>n;

    vector<int> arr(10000000, 1);

    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2 ; i * i<10000000 ; i++)
    {
        if(!arr[i]) continue;
        for(int j = i * i ; j<10000000 ; j += i)
        {
            arr[j] = 0;
        }
    }

    while(n != 1)
    {
        if(arr[n])
        {
            cout<<n<<endl;
            break;
        }

        if(n%2 == 0)
        {
            cout<<2<<endl;
            n /= 2;
            continue;
        }

        for(int i = 3 ; i<n ; i+=2)
        {
            if(arr[i] && n%i == 0)
            {
                cout<<i<<endl;
                n /= i;
                break;
            }
        }
    }
}