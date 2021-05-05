#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_squre(unsigned int n) {
    int root = sqrt(n);
    return root * root == n;
}

/*
    Check the number of the divisors, d, of the input number, N,
    if d is odd, then the nth light would be turned on and output "yes",
    otherwise, tured off and output "no".

    But if we calculate d in directly, then TLE is occured.
    The number of the divisors of N is odd hints that N is a squre number.
    So we only need to check whether N is a squre or not.
*/

int main() {
    unsigned int n;
    bool status;
    while (cin >> n) {
        if (n == 0) break;
        cout << ((is_squre(n)) ? "yes" : "no") << endl;
    }

    return 0;
}
