#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

vector<bool> create_primes(uint n) {
    if (n < 2) return {false, false};
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (uint i = 2; i <= n; i++) {
        if (!primes[i]) continue;
        for (uint j = i + i; j <= n; j += i) primes[j] = false;
    }
    return primes;
}

int main() {
    uint size = sqrt(UINT_MAX);
    vector<bool> primes = create_primes(size);
    vector<uint> prime_list;
    for (uint i = 2; i < primes.size(); i++)
        if (primes[i]) prime_list.push_back(i);

    uint lo, hi;
    while (cin >> lo >> hi) {
        vector<uint> res(4);
        uint max_d = 0, min_d = UINT_MAX;
        uint prev = -1;
        for (uint i = lo; i <= hi; i++) {
            bool is_prime = true;
            if (i <= size)
                is_prime = primes[i];
            else {
                for (uint k = 0; k < prime_list.size() && prime_list[k] < i;
                     k++)
                    if (i % prime_list[k] == 0) {
                        is_prime = false;
                        break;
                    }
            }
            if (is_prime) {
                if (prev != -1) {
                    uint d = i - prev;
                    if (max_d < d) {
                        res[2] = prev;
                        res[3] = i;
                        max_d = d;
                    }
                    if (min_d > d) {
                        res[0] = prev;
                        res[1] = i;
                        min_d = d;
                    }
                }
                prev = i;
            }
        }
        if (res[0] == 0)
            cout << "There are no adjacent primes." << endl;
        else
            cout << res[0] << "," << res[1] << " are closest, " << res[2] << ","
                 << res[3] << " are most distant." << endl;
    }
}
