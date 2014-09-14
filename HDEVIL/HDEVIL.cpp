#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int t;
    scanf("%i", &t);
    for(int tt=1; tt <= t; tt++) {
        ull n, m;
        scanf("%llu %llu", &n, &m);
        ull sumdiv = 1, i;
        for(i=2; i*i < n; i++) {
            if (n%i == 0){
                sumdiv += i+(n/i);
            }
        }

        if (i*i == n)
            sumdiv += i;
        sumdiv = sumdiv % m;
        ull count=1;
        for(i=2; i*i < sumdiv; i++) {
            if (sumdiv%i == 0)
                count+=2;
        }
        if (i*i == sumdiv)
            count++;
        ull c1 = 5*count*count + 4, c2 = c1 - 8, s1 = sqrt(c1), s2 = sqrt(c2);
        if (s1*s1 == c1 || s2*s2 == c2)
            printf("Case #%i : YES.\n", tt);
        else 
            printf("Case #%i : NO.\n", tt);
            
    }
    return 0;
}

