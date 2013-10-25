#include<stdio.h>
#include<math.h>
using namespace std;
typedef unsigned long long bignum;
bignum modexp(bignum base, bignum exponent){
	bignum ans=1;
	while(exponent > 0){
		if(exponent & 1)
			ans=(ans*base)%10000007;
		exponent>>=1;
		base=(base*base)%10000007;
	}
	return ans;
}

int main(){
	int n, k;
	while(true){
		scanf("%i %i", &n, &k);
		if(n==0)
			return 0;
		bignum ans=(modexp(n, n) + modexp(n, k) + 2*modexp(n-1, k) + 2*modexp(n-1, n-1))%10000007;
		printf("%llu\n", ans);

	}
}
