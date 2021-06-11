#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    int case_num = 0;
    while(scanf("%d", &n) && n!=0){        
        int s;
        scanf("%d", &s);
        vector<vector<int> > adj(n+1);
        vector<int> dis(n+1, INT_MIN);
        int p, q;
        while(scanf("%d %d", &p, &q) && p!=0 && q!=0)
            adj[p].push_back(q);
        priority_queue<pair<int, int>, vector<pair<int, int> > > pq;
        dis[s] = 0;
        pq.push({dis[s], s});
        while(!pq.empty()){
            pair<int, int> t = pq.top();
            pq.pop();
            int u = t.second;
            int d = t.first;
            for(int v: adj[u]){
                if(dis[v] < d+1){
                    dis[v] = d+1;
                    pq.push({dis[v], v});
                }
            }
        }
        int longest_dis = 0;
        int dst;
        for(int i=1; i<=n; i++){
            if(longest_dis < dis[i]){
                longest_dis = dis[i];
                dst = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++case_num, s, longest_dis, dst);
    }

    return 0;
}
