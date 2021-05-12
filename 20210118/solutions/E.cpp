#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        set<long long> nums;
        for (int i = 0; i < n; i++) {
            long long buf;
            cin >> buf;
            nums.insert(buf);
        }
        bool solved = false;
        for (auto i = nums.rbegin(); i != nums.rend() && !solved; i++) {
            for (auto j = nums.rbegin(); j != nums.rend() && !solved; j++) {
                for (auto k = next(j); k != nums.rend() && !solved; k++) {
                    int a = *i - *j - *k;
                    if (*i == *j || *j == *k) continue;
                    if (a == *i || a == *j || a == *k) continue;
                    if (nums.count(a)) {
                        solved = true;
                        cout << *i << endl;
                    }
                }
            }
        }

        if (!solved) cout << "no solution" << endl;
    }

    return 0;
}
