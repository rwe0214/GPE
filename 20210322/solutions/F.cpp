#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
    There n marbles and two types of boxes:

    type0: c0, n1 (cost, holds)
    type1: c1, n2

    we want to minimize the cost of buying two types of boxes for storing n
   marbles and each box should be filled.

    assume there x boxes0 and y boxes1,

    objective : min(cost) = min(x*c0 + y*c1)
    constraint: 1. n = x*n1 + y*n2,
                2. x >= 0,
                3. y >= 0

    if there exists some solution which satisfie the constriant 1, then gcd(n1,
   n2) | n

    solve:
        * applied constraint 1
        * use extend euclidean algorithm to calculate x', y' and gcd(n1, n2)
        let g = gcd(n1, n2)
        x'n1 + y'n2 = g, let r = n / g
        -> xn1 + yn2 = n
        -> (nx'/g)n1 + (ny'/g)n2 = n

        (nx'/g+kn2/g)n1 + (ny'/g-kn1/g)n2 = n

        * applied constraint 2 & 3
        nx'+kn2 >= 0, ny'-kn1 >= 0
        -> nx'/n2 <= k <= ny'/n1
*/

typedef long long ll;

// {r, s, t}
// s*a + t*b = r = gcd(a, b)
vector<ll> ex_gcd(ll a, ll b) {
    if (b == 0) return {a, 1ll, 0ll};
    vector<ll> res = ex_gcd(b, a % b);
    ll tmp = res[1];
    res[1] = res[2];
    res[2] = tmp - a / b * res[2];
    return res;
}

int main() {
    ll n;
    while (cin >> n) {
        if (n == 0ll) break;
        ll c1, c2, n1, n2;
        cin >> c1 >> n1;
        cin >> c2 >> n2;

        // param = {gcd(n1, n2), x', y'}
        vector<ll> param = ex_gcd(n1, n2);
        ll upper_bound = floor((1.0) * n * param[2] / n1);
        ll lower_bound = ceil((-1.0) * n * param[1] / n2);

        if (n % param[0] || lower_bound > upper_bound)
            cout << "failed" << endl;
        else if (c1 * n2 >= c2 * n1) {
            ll r = n / param[0];
            ll r_k = lower_bound / param[0];
            ll x = r * param[1] + r_k * n2;
            ll y = r * param[2] - r_k * n1;
            cout << x << " " << y << endl;
        } else {
            ll r = n / param[0];
            ll r_k = upper_bound / param[0];
            ll x = r * param[1] + r_k * n2;
            ll y = r * param[2] - r_k * n1;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
