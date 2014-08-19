#include<bits/stdc++.h>
using namespace std;

int main() {
    int factors[1000030];

//    fill_n(sieve, 1000000, true);
    fill_n(factors, 1000030, 0);

    for(int i=2; i<=1002; i++) {
        if (factors[i] == 0){
            for(int j=i; j<=1000020; j+=i){
                factors[j]++;
            }
        }
    }
    vector<int> lucky;
    for(int i=30; i<1000000; i++){
        if (factors[i] >= 3)
            lucky.push_back(i);
    }

    int t;
    scanf("%i", &t);
//    printf("%i\n", factors[42]);
    while(t--) {
        int n;
        scanf("%i", &n);
        printf("%i\n", lucky[n-1]);
    }
    return 0;
}
