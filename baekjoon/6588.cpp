#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> arr(1000001, 1);
    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2 ; i * i<=1000000 ; i++)
    {
        if(arr[i] == 0)   continue;

        for(int j = i*i ; j<=1000000 ; j+=i)
        {
            arr[j] = 0;
        }
    }

    while(true)
    {
        int n;
        cin>>n;
        if(!n)  break;
        
        int left = 3;
        int right = n-3;

        while(left <= right)
        {
            if(arr[left] && arr[right])
            {
                if(left+right == n) break;
            }
            left+=2;
            right -= 2;
        }
        if(left>right)  cout<<"Goldbach's conjecture is wrong.";
        else     cout<<n<<" = "<<left<<" + "<<right<<'\n';   
    }
}