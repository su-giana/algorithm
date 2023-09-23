#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    int a_len = a.length();
    int b_len = b.length();

    vector<vector<int>> dp(a_len + 1, vector<int>(b_len + 1, 0));

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcs_length = dp[a_len][b_len];

    cout << lcs_length << '\n';

    string lcs;
    lcs.resize(lcs_length); // Preallocate memory for the LCS

    int i = a_len, j = b_len, index = lcs_length - 1;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[index] = a[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << lcs << '\n';

    return 0;
}
