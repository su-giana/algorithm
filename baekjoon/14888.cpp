#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<long> nums;
vector<int> operators(4, 0);

void getInput( ) {
    cin>>n;
    for(int i = 0 ; i<n ; i++) {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    for(int i = 0 ; i<4 ; i++) {
        cin>>operators[i];
    }
}

long minDfs(vector<long> nums, vector<int> operators) {
    if(nums.size() == 1)    return nums[0];

    long first = nums[0];
    long second = nums[1];
    nums.erase(nums.begin());
    nums.erase(nums.begin());
    long ans = LONG_MAX;
    
    for(int i = 0 ; i<4 ; i++) {
        if(operators[i] > 0) {
            long next = 0;
            if(i == 0) {
                next = first + second;
            }
            else if(i==1) {
                next = first - second;
            }
            else if(i == 2) {
                next = first * second;
            }
            else if(i == 3) {
                next = first / second;
            }
            nums.insert(nums.begin(), next);
            operators[i]--;
            ans = min(ans, minDfs(nums, operators));
            operators[i]++;
            nums.erase(nums.begin());
        }
    }

    return ans;
}

long maxDfs(vector<long> nums, vector<int> operators) {
    if(nums.size() == 1)    return nums[0];

    long first = nums[0];
    long second = nums[1];
    nums.erase(nums.begin());
    nums.erase(nums.begin());
    long ans = LONG_MIN;
    
    for(int i = 0 ; i<4 ; i++) {
        if(operators[i] > 0) {
            long next = 0;
            if(i == 0) {
                next = first + second;
            }
            else if(i==1) {
                next = first - second;
            }
            else if(i == 2) {
                next = first * second;
            }
            else if(i == 3) {
                next = first / second;
            }
            nums.insert(nums.begin(), next);
            operators[i]--;
            ans = max(ans, maxDfs(nums, operators));
            operators[i]++;
            nums.erase(nums.begin());
        }
    }

    return ans;
}

void solve( ) {
    getInput( );

    cout<<maxDfs(nums, operators)<<'\n';
    cout<<minDfs(nums, operators)<<'\n';
}

int main( ) {
    solve();
}