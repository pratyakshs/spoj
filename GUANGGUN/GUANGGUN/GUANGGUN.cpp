#include<bits/stdc++.h>
typedef unsigned long long bignum;
int main(){
	bignum n;
	while(scanf("%llu", &n)!=EOF)
		printf("%llu\n", (81*(n/9))+(n%9)*(n%9));
}
