#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int money[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    long long dp[30001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int k = 10; k >= 0; k--)
        for (int i = money[k]; i < 30001; i++) dp[i] += dp[i - money[k]];

    int int_part, frac_part;
    while (scanf("%d.%d", &int_part, &frac_part) != EOF &&
           (int_part != 0 || frac_part != 0)) {
        int amount = int_part * 100 + frac_part;
        printf("%3d.%02d%17lld\n", int_part, frac_part, dp[amount]);
    }
    return 0;
}
