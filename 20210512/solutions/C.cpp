#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)){
        if(n == 0)
            break;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end(), greater<int>());
        bool solved = false;
        for(auto d=arr.begin(); d<arr.end() && !solved; d++){
            for(auto a=arr.begin(); a<arr.end() && !solved; a++){
                for(auto b=next(a); b<arr.end() && !solved; b++){
                    for(auto c=next(b); c<arr.end() && !solved; c++){
                        if(*a == *b || *a == *c)
                            continue;
                        if(*b == *c)
                            continue;
                        if(*d == *a || *d == *b || *d == *c)
                            continue;
                        if(*d == *a+*b+*c){
                            solved = true;
                            printf("%d\n", *d);
                        }

                    }
                }
            }

        }
        if(!solved)
            printf("no solution\n");
    }

    return 0;
}
