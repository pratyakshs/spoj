#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long bignum;

inline bignum mulmod(bignum a,bignum b,bignum c){ 
	bignum x = 0,y=a%c;
	while(b > 0){ 

		if(b%2 == 1){ 
			x = (x+y)%c;
		}
		y = (y<<1)%c;
		b >>= 1;
		//printf("%llu))\n", b);
	}   
	return x%c;
}

inline bignum modexp(bignum base, bignum exponent, bignum modulo)
{//implement for the case when base is an nxn matrix. Targeted running time: O(n^3 log(exponent)).
	bignum ans=1;
	while(exponent>0)
	{   
		//printf("%llu)\n", exponent);
		if(exponent&1==1)
//			ans=mulmod(ans, base, modulo);
			ans=(ans*base)%modulo;
		exponent>>=1;
//		base=mulmod(base, base, modulo);
		base=(base*base)%modulo;
	}   
	return ans;
}

int main() {
	bignum n;
	while(scanf("%llu", &n)!=EOF) {
//	for (bignum n = 0; n < 100; n ++) {

//		printf("%llu\n", offset);

		printf("%llu\n", 1 + (((modexp(2, n, 1000000007) - 1 - (n&1))*333333336)% 1000000007));
	}
	return 0;
}
