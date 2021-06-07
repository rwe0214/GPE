#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int d;
    vector<vector<int> > cache(4);
    while(scanf("%d", &d)!=EOF){
        int mask = 1;
        for(int i=0; i<d/2; i++)
            mask*=10;
        int upper = mask*mask;
        int key = d/2-1;
        if(!cache[key].empty()){
            for(int num:cache[key])
                printf("%0*d\n", d, num);
            continue;
        }
        for(int i=0; i<upper; i++){
            int a = i%mask;
            int b = (i-a)/mask;
            int sum = a+b;
            if(sum*sum == i){
                printf("%0*d\n", d, i);
                cache[key].push_back(i);
            }
        }
    }
    
    return 0;
}
