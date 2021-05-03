#include <iostream>
#include <vector>

using namespace std;

/*
    dp[i][j][k] := the number of the lowercase letters combinations in strictly
   ascending order, the range of letters are 1 to i, the length of the
   combination is j and the sum of the letters are k.

    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-i]
                   (with 'i')       (without 'i')
*/

int main() {
    int n = 26;
    int max_val = (1 + 26) * 13;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(max_val + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= max_val; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j && k >= i) dp[i][j][k] += dp[i - 1][j - 1][k - i];
            }

    int L, S, k = 0;
    while (cin >> L >> S) {
        if (L == 0 && S == 0) break;
        cout << "Case " << ++k << ": "
             << ((L <= n && S <= max_val) ? dp[26][L][S] : 0) << endl;
    }
    return 0;
}
