#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct DSJ{
    DSJ(int n){
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int find(int k){
        if(parent[k] != k)
            parent[k] = find(parent[k]);
        return parent[k];
    }

    void _union(int i, int j){
        // union j into i
        parent[find(parent[j])] = find(parent[i]);
    }

    vector<int> parent;
};

int main(){
    int k;
    cin >> k;
    while(k){
        int n, pos = 0, neg = 0;
        cin >> n;
        DSJ computers(n+1);
        string buf;
        cin.ignore();
        while(getline(cin, buf) && !buf.empty()){
            char status;
            int i, j;
            stringstream ss(buf);
            ss >> status >> i >> j;
            if(status == 'c')
                computers._union(i, j);      
            else{
                if(computers.find(i) == computers.find(j))
                    pos++;
                else
                    neg++;
            }
        }

        cout << pos << "," << neg << endl;
        if(k>1)
            cout << endl;
        k--;
    }

    return 0;
}
