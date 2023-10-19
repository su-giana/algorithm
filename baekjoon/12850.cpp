#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<long long> > campus = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 1, 0}
};

vector<vector<long long> > multiplyMatrix(const vector<vector<long long> >& matA, const vector<vector<long long> >& matB)
{
    vector<vector<long long> > result(8, vector<long long>(8, 0));
    for(int i = 0 ; i<8 ; i++)
    {
        for(int j = 0 ; j<8 ; j++)
        {
            for(int k = 0 ; k<8 ; k++)
            {
                result[i][j] = (result[i][j] + (matA[i][k] * matB[k][j]) % 1000000007) % 1000000007;
            }
        }
    }

    return result;
}

vector<vector<long long> > divAndConq(vector<vector<long long> >& matrix, long long time)
{

    if(time == 1)   return matrix;

    long long half = time / 2;
    vector<vector<long long> > sqrtMatrix = divAndConq(matrix, half);

    if(time % 2 == 0)
    {
        return multiplyMatrix(sqrtMatrix, sqrtMatrix);
    }
    else
    {
        return multiplyMatrix(multiplyMatrix(sqrtMatrix, sqrtMatrix), matrix);
    }
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    init();

    long long time;
    cin>>time;

    vector<vector<long long> > ans = divAndConq(campus, time);
    cout<<ans[0][0];
}