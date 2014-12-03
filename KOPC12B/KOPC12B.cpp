#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll fact[2000020], ifact[2000020];

struct mypair{
    ll x,y;
    mypair(ll a, ll b){
        x=a, y=b;
    }
};

mypair bezout(ll a, ll m){
    if(m==0)
        return mypair(1, 0);
    mypair p=bezout(m, a%m);
    return mypair(p.y, (p.x-(p.y*(a/m))));
}

ll modInv(ll a){
    mypair p=bezout(a,MOD);
    if(p.x<0)
        return p.x+MOD;
    return p.x;
}

ll nCr(ll n, ll r) {
	return (((fact[n]*ifact[r]) % MOD) * ifact[n-r]) % MOD;
}

int main() {
	
	
	fact[0] = 1;
	ifact[0] = modInverse(1);
	for(ll i = 1; i < 2000020; i++)
		fact[i] = (i * fact[i-1]) % MOD;

	for (ll i = 1; i < 1000010; i++)
		ifact[i] = (ifact[i-1] * modInverse(i)) % MOD;

	ll t, n;
	scanf("%lli", &t);
	while(t--){
		scanf("%lli", &n);
		ll ans = (n * nCr(2*n-1, n-1)) % MOD;
		printf("%lli\n", ans);
	}
}
