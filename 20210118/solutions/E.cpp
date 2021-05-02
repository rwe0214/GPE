#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n && n!=0){
        vector<int> nums;
        for(int i=0; i<n; i++){
            int buf;
            cin >> buf;
            nums.push_back(buf);
        }
        sort(nums.begin(), nums.end());
        int a, lo, hi, d;
        bool solved = false;
        for(int i=n-1; i>=3 && !solved; i--){
            d = nums[i];
            for(int j=0; j<i && !solved; j++){
                a = nums[j];
                lo = j+1;
                hi = i-1;
                while(lo < hi && !solved){
                    int test = a+nums[lo]+nums[hi];
                    if(test == d){
                        solved = true;
                        cout << d << endl;
                    }
                    else if(test < d)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        if(!solved)
            cout << "no solution" << endl;
    }   

    return 0;
}
