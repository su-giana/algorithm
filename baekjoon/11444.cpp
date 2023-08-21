#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<long long> > matrix = { {1, 1}, {1, 0} };

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<long long> > multiplyMatrix(vector<vector<long long> > matrix1, vector<vector<long long> > matrix2)
{
    int c2 = matrix2[0].size();
    vector<vector<long long> > res(2, vector<long long>(c2, 0));

    for(int i = 0 ; i<2 ; i++)
    {
        for(int j = 0 ; j<c2 ; j++)
        {
            for(int k = 0 ; k<2 ; k++)
            {
                res[i][j] = (res[i][j] + matrix1[i][k] * matrix2[k][j] % 1000000007) % 1000000007;
            }
        }
    }

    return res;
}

vector<vector<long long> > divAndConquer(long long n, vector<vector<long long> > matrix)
{
    if(n==1)    return matrix;
    vector<vector<long long> > tmp = divAndConquer(n/2, matrix);

    if(n%2==0)
    {
        return multiplyMatrix(tmp, tmp);
    }
    else
    {
        return multiplyMatrix(multiplyMatrix(tmp, tmp), matrix);
    }
}

int main()
{
    init();

    long long n;
    cin>>n;

    if(n<3)
    {
        cout<<1;
        return 0;
    }

    cout<<multiplyMatrix(divAndConquer(n-1, matrix), {{1}, {0}})[0][0];
}