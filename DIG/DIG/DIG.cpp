#include<bits/stdc++.h>
#define modulo 1000000007
typedef unsigned long long bignum;
int main(){
	bignum t, n,a1, a2;
	scanf("%llu", &t);
	while(t--){
		scanf("%llu", &n);
		a1=n*(n-1); a2=(n-2)*(n-3);
		if(a1%3==0) a1/=3;
		else if(a2%3==0) a2/=3;
		if(a1%4==0) a1=a1>>2;
		else a2=a2>>2;
		if(a1%2==0) a1=a1>>1;
		else a2=a2>>1;
		printf("%lli\n", ((a1%modulo)*(a2%modulo))%modulo);
	}
	return 0;
}
