#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        int m=s1.size(), n=s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}
