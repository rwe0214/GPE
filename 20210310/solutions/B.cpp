#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define N 50000

int digit_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

vector<bool> create_primes(int n) {
    if (n < 2) return {false, false};
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!primes[i]) continue;
        for (int j = i + i; j <= n; j += i) primes[j] = false;
    }
    return primes;
}

vector<int> prime_factorize(int n, const vector<bool> &primes) {
    int tmp = n;
    int sqrt_tmp = (int)(sqrt(n) + 1e-9);
    vector<int> factors;
    for (int i = 2; i <= sqrt_tmp && tmp > 1; i++) {
        if (!primes[i]) continue;
        while (tmp % i == 0) {
            factors.push_back(i);
            tmp /= i;
        }
    }
    if (tmp > 1) factors.push_back(tmp);
    return factors;
}

int main() {
    vector<bool> primes = create_primes(N);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int smith_number = k + 1;
        bool find = false;
        while (!find) {
            vector<int> factors = prime_factorize(smith_number, primes);
            if (factors.back() == smith_number) {
                smith_number++;
                continue;
            }
            int sum0 = digit_sum(smith_number);
            int sum1 = 0;
            for (int f : factors) sum1 += digit_sum(f);
            if (sum0 == sum1)
                find = true;
            else
                smith_number++;
        }
        cout << smith_number << endl;
    }
    return 0;
}
