#include <iostream>
#include <vector>

using namespace std;

/*
    dp[i] := the kth bit of dp[i] is set means that there are k people whose
   weight sum is i

    dp[i] = dp[i] | (dp[i-weights[j]] << 1)


    the 2d dp solution:
    dp[k][i] := if true, then there k people whose weight sum is i

    dp[k][i] = dp[k-1][i-weights[j]]

*/

int main() {
    int n;
    cin >> n;
    vector<long long> dp(450 * 100 + 1);
    while (n--) {
        int k;
        cin >> k;
        vector<int> weights(k);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            cin >> weights[i];
            sum += weights[i];
        }
        fill(dp.begin(), dp.begin() + sum / 2 + 1, 0ll);
        dp[0] = 1ll;
        for (int i = 0; i < k; i++) {
            for (int j = sum / 2; j >= weights[i]; j--) {
                dp[j] = dp[j] | (dp[j - weights[i]] << 1);
            }
        }
        int w0;
        k = weights.size();
        for (w0 = sum / 2; w0 >= 0; w0--) {
            if ((k & 1) && (dp[w0] & (1ll << (k / 2)))) break;
            if ((k & 1) && (dp[w0] & (1ll << ((k + 1) / 2)))) break;
            if (!(k & 1) && (dp[w0] & (1ll << (k / 2)))) break;
        }

        cout << w0 << " " << sum - w0 << endl;
        if (n > 0) cout << endl;
    }
    return 0;
}
