#include <iostream>
#include <vector>

using namespace std;

long long n, b;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<long long> > multiplyMatrix(vector<vector<long long> > matrixA, vector<vector<long long> > matrixB)
{
    vector<vector<long long> > ans(n, vector<long long>(n, 0));

    for(long long i = 0 ; i<n ; i++)
    {
        for(long long j = 0 ; j<n ; j++)
        {
            for(long long k = 0 ; k<n ; k++)
            {
                long long val = (long long) matrixA[i][k] * matrixB[k][j] % 1000;
                ans[i][j] = (ans[i][j] + val) % 1000;
            }
        }
    }

    return ans;
}

void trimMatrix(vector<vector<long long> >& matrix)
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            matrix[i][j] %= 1000;
        }
    }
}

vector<vector<long long> > divAndConquer(long long b, vector<vector<long long> > matrix)
{
    trimMatrix(matrix);
    if(b==1)    return matrix;

    vector<vector<long long> > square = divAndConquer(b/2, matrix);

    if(b%2==0)
    {
        return multiplyMatrix(square, square);
    }
    else
    {
        return multiplyMatrix(multiplyMatrix(square, square), matrix);
    }
}

int main()
{
    init();

    vector<vector<long long> > matrix(5, vector<long long>(5, 0));
    cin>>n>>b;

    for(long long i = 0 ; i<n ; i++)
    {
        for(long long j = 0 ; j<n ; j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<vector<long long> > ans = divAndConquer(b, matrix);

    for(long long i = 0 ; i<n ; i++)    
    {
        for(long long j = 0 ; j<n ; j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}