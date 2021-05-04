#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M == 0 && N == 0) break;
        vector<int> teams(M);
        vector<vector<int> > tables(N, vector<int>(2));
        for (int i = 0; i < M; i++) cin >> teams[i];

        for (int i = 0; i < N; i++) {
            cin >> tables[i][0];
            tables[i][1] = i + 1;
        }

        vector<vector<int> > output(M);
        bool invalid = false;
        for (int i = 0; i < M && !invalid; i++) {
            sort(tables.begin(), tables.end(), greater<vector<int> >());
            if (teams[i] > N) {
                invalid = true;
                break;
            }
            // always select from the table with maximum resident space
            for (int k = 0; k < teams[i]; k++) {
                if (tables[k][0] <= 0) {
                    invalid = true;
                    break;
                }
                tables[k][0]--;
                output[i].push_back(tables[k][1]);
            }
            sort(output[i].begin(), output[i].end());
        }
        if (invalid)
            cout << "0" << endl;
        else {
            cout << "1" << endl;
            for (int i = 0; i < M; i++) {
                cout << output[i].front();
                for (int k = 1; k < output[i].size(); k++)
                    cout << " " << output[i][k];
                cout << endl;
            }
        }
    }
    return 0;
}