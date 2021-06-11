#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

#define BUF_SIZE 256
#define MAX_NUM 10005

using namespace std;

struct Edge{
    int dst;
    int distance;
    Edge(int i, int d){dst=i; distance=d;}
};

int dfs(int u, int prev, int &ans, vector<vector<Edge> > &adj){
    int max_dis = 0;
    for(Edge e: adj[u]){
        int v = e.dst;
        if(v == prev)
            continue;
        int cur_dis = e.distance + dfs(v, u, ans, adj);
        ans = max(ans, cur_dis+max_dis);
        max_dis = max(max_dis, cur_dis);
    }
    return max_dis;
}

void clear(vector<vector<Edge> > &adj){
    for(int i=0; i<adj.size(); i++)
        adj[i].clear();        
}

int main(){
    char buf[BUF_SIZE+1];
    int ans = 0;
    bool solved = false;
    vector<vector<Edge> > adj(MAX_NUM);
    while(cin.getline(buf, BUF_SIZE)){
        if(buf[0] == '\0'){
            ans = 0;
            dfs(1, -1, ans, adj);
            printf("%d\n", ans);
            clear(adj);
            solved = true;
        }
        else{
            int u, v, d;
            sscanf(buf, "%d %d %d", &u, &v, &d);
            adj[u].push_back(Edge(v, d));
            adj[v].push_back(Edge(u, d));
            solved = false;
        }
    }

    if(!solved){
        dfs(1, -1, ans, adj);
        printf("%d\n", ans);
    }

    return 0;
}
