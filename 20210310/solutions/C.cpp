#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct point {
    int x;
    int y;
};

double euclidean_distance(point a, point b) {
    int diff_x = (a.x - b.x);
    int diff_y = (a.y - b.y);
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        point origin;
        cin >> origin.x >> origin.y;
        cin.ignore();
        string buf;
        double dis = 0;
        while (getline(cin, buf) && !buf.empty()) {
            stringstream ss(buf);
            point begin, end;
            ss >> begin.x >> begin.y >> end.x >> end.y;
            dis += euclidean_distance(begin, end);
        }
        dis /= 1000;
        double time = dis / 20 * 2;
        int minutes = (int)round(time * 60);
        cout << minutes / 60 << ":" << setw(2) << setfill('0') << minutes % 60
             << endl;
        if (n) cout << endl;
    }
    return 0;
}