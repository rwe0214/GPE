#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m, case_num = 1;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<int> cap(n, -1);
        vector<bool> visit(n, false);
        vector<vector<int> > adj(n, vector<int>());
        vector<vector<int> > weight(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            weight[u][v] = weight[v][u] = w;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int s, d, t;
        cin >> s >> d >> t;
        s--;
        d--;

        priority_queue<pair<int, int>, vector<pair<int, int> >,
                       less<pair<int, int> > >
            pq;
        pq.push(make_pair(INT_MAX, s));
        cap[s] = INT_MAX;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visit[u]) continue;
            visit[u] = true;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                cap[v] = max(cap[v], min(cap[u], weight[u][v]));
                pq.push(make_pair(cap[v], v));
            }
        }

        cap[d] = cap[d] - 1;
        int times = (t % cap[d]) ? t / cap[d] + 1 : t / cap[d];
        cout << "Scenario #" << case_num++ << endl;
        cout << "Minimum Number of Trips = " << times << endl;
        cout << endl;
    }
}
