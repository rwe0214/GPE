#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, m, case_num = 1;
	while(cin >> n >> m && n!=0 && m!=0){
		int limit[n][n];
		memset(limit, 0, sizeof(limit));

		for(int i=0; i<m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			limit[u][v] = limit[v][u] = w;
		}

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					limit[i][j] = max(limit[i][j], min(limit[i][k], limit[k][j]));
		
		int s, d, t;
		cin >> s >> d >> t;
		s--; d--;
		int cap = limit[s][d] - 1;
		int times = (t%cap) ? t/cap+1 : t/cap;
		cout << "Scenario #" << case_num++ << endl;
		cout << "Minimum Number of Trips = " << times << endl;
		cout << endl;
	}
}
