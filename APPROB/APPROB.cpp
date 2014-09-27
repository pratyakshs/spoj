#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%i", &t);
    while(t--) {
        ll n;
        scanf("%lli", &n);
        ll t1 = (n+1)>>1, t2 = (3*n+1)>>1;
        ll num = t1*t2 + (n-t1)*(3*n-t2);
        ll den = 6*n*n*n;
        ll g = __gcd(num, den);
        num /= g;
        den /= g;
        printf("%lli/%lli\n", num, den);
    }
    return 0;
}
