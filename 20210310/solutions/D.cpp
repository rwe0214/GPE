#include <iostream>
#include <vector>

using namespace std;

vector<int> ex_gcd(int a, int b) {
    int old_s = 1, s = 0;
    int old_t = 0, t = 1;
    int old_r = a, r = b;
    if (b == 0) return {1, 0, a};
    while (r != 0) {
        int q = old_r / r;
        int tmp = old_r;
        old_r = r;
        r = tmp - q * r;
        tmp = old_s;
        old_s = s;
        s = tmp - q * s;
        tmp = old_t;
        old_t = t;
        t = tmp - q * t;
    }
    return {old_s, old_t, old_r};
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        vector<int> ans = ex_gcd(a, b);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
    return 0;
}
