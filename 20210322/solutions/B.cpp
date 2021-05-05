#include <iostream>
#include <vector>

using namespace std;

/*
    S = [n], Si = n

    V = [m+S], Vi = m          , when i = 1
                  = Vi-1 + Si-1, when i > 1
    V = [m*S], Vi = m * S1     , when i = 1
                  = Vi-1 * Si  , when i > 1

    Examples:
    [2+[1]] = [2, 2+1, (2+1)+1, ...]
    [1+[2+[1]]] = [1+[2, 3, 4, ...]] = [1, 3, 6, 10]
*/

enum operation { UNDEFINED = 0, ADD, MULTIPLY };

vector<int> parse(string V, int n) {
    int op = UNDEFINED, m = 0, sign = 1;
    int begin;
    for (begin = 0; begin < V.size(); begin++) {
        char c = V[begin];
        if (c == '[' || c == ']') continue;
        if (c >= '0' && c <= '9') {
            m = m * 10 + c - '0';
            continue;
        }
        if (c == '-') {
            sign = -1;
            continue;
        }
        op = (c == '+') ? ADD : MULTIPLY;
        begin++;
        break;
    }
    m *= sign;
    if (op == UNDEFINED) return vector<int>(n, m);
    vector<int> S = parse(V.substr(begin, V.size() - begin - 1), n);
    vector<int> output;
    if (op == ADD) {
        output.push_back(m);
        for (int i = 1; i < n; i++) output.push_back(output[i - 1] + S[i - 1]);
    } else {
        output.push_back(m * S.front());
        for (int i = 1; i < n; i++) output.push_back(output[i - 1] * S[i]);
    }
    return output;
}

int main() {
    string V;
    int n;
    while (cin >> V >> n) {
        vector<int> S = parse(V, n);
        cout << S.front();
        for (int i = 1; i < S.size(); i++) cout << " " << S[i];
        cout << endl;
    }

    return 0;
}
