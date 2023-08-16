#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int a, b, c;

long long int recur(long long int x, long long int y, long long int z,long long int w) {
	if (y == 1) {
		return  (x * w) % z;
	}
	
	if (y % 2 == 1) {
		w *= x;
		w %= z;
		y -= 1;
	}
	long long int r = (x * x) % z;

	return recur(r, y / 2, z, w);
}

int main()
{
    cin>>a>>b>>c;

    cout<<recur(a, b, c, 1);
}