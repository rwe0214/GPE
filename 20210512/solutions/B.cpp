#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

#define MAX_PRIME 1000000

using namespace std;

int digit_sum(int num){
    int sum = 0;
    while(num > 0){
        sum += num%10;
        num /= 10;
    }
    return sum;
}

vector<int> build_digit_primes(int n){
    vector<bool> is_prime(n, true);
    vector<int> primes(n, 0);
    is_prime[0] = is_prime[1] = false;
    primes[0] = primes[1] = 0;

    for(int i=2; i<n; i++){
        if(!is_prime[i]){
            primes[i] = primes[i-1];
            continue;
        }
        // for(int j=i*2; j<n; j+=i)
        //     is_prime[j] = false;
        for(int k=(n-1)/i, j=i*k; k>=i; k--, j-=i)
            if(is_prime[k])
                is_prime[j] = false;
        int sum = digit_sum(i);
        primes[i] = primes[i-1]+is_prime[sum];    
    }
    return primes;
}

int main(){
    vector<int> primes = build_digit_primes(MAX_PRIME);
    int t, lower, upper;
    scanf("%d", &t);
    for(int k=0; k<t; k++){
        scanf("%d %d", &lower, &upper);
        printf("%d\n", primes[upper]-primes[lower-1]);
    }

    return 0;
}
